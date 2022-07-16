// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <array>
#include <concepts>
#include <iostream>
#include <range/v3/algorithm/for_each.hpp>
#include <range/v3/functional/arithmetic.hpp>
#include <range/v3/range/dangling.hpp>
#include <range/v3/view.hpp>
#include <range/v3/view/join.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/zip.hpp>
#include <ranges>
#include <vector>

template<class T>
concept Number = std::integral<T> || std::floating_point<T>;

template<class T>
concept Vector = std::ranges::range<T> && Number<typename T::value_type>;

template<class T>
concept Point2D = Vector<T> && std::tuple_size_v<T> == 2;

template<class T>
concept Point3D = Vector<T> && std::tuple_size_v<T> == 3;

template<class T>
concept Point = Point2D<T> || Point3D<T>;

namespace views
{
namespace detail
{
    template<class Rng, Point Vec, class Proj>
    class transform_view : public ranges::view_adaptor<transform_view<Rng, Vec, Proj>, Rng>
    {
        friend ranges::range_access;
        ranges::semiregular_box_t<Proj> proj_;
        Vec vec_;
        class adaptor : public ranges::adaptor_base
        {
            Vec vec_;
            ranges::semiregular_box_t<Proj> proj_;

          public:
            adaptor() = default;
            adaptor(const Vec& vec, ranges::semiregular_box_t<Proj> proj) : vec_{ vec }, proj_{ proj } {};

            inline constexpr auto read(ranges::iterator_t<Rng> it) const
            {
                return ranges::views::zip(*it, vec_)
                     | ranges::views::transform([&](const auto& pair) { return std::invoke(proj_, pair.first, pair.second); });
            }
        };

        [[maybe_unused, nodiscard]] adaptor begin_adaptor() const
        {
            return adaptor{ vec_, proj_ };
        }

        [[maybe_unused, nodiscard]] adaptor end_adaptor() const
        {
            return adaptor{ vec_, proj_ };
        }

      public:
        transform_view() = default;
        transform_view(Rng&& rng, Vec vec, Proj proj)
          : transform_view::view_adaptor{ std::forward<Rng>(rng) }, vec_{ std::move(vec) }, proj_{ std::move(proj) }
        {
        }
    };

    template<class Rng, Point Vec, class Proj>
    transform_view<Rng, Vec, Proj> transform_fn(Rng&& rng, Vec vec, Proj&& proj)
    {
        return { std::forward<Rng>(rng), std::move(vec), std::forward<Proj>(proj) };
    }
} // namespace detail

inline constexpr auto transform(Point auto& vec, auto&& proj)
{
    return ranges::make_view_closure(
      [&vec, &proj](auto&& rng)
      { return detail::transform_fn(std::forward<decltype(rng)>(rng), vec, std::forward<decltype(proj)>(proj)); });
}

inline constexpr auto translate(Point auto& vec)
{
    return ranges::make_view_closure(
      [&vec](auto&& rng)
      { return detail::transform_fn(std::forward<decltype(rng)>(rng), vec, std::forward<ranges::plus>(ranges::plus{})); });
}

inline constexpr auto scale(Point auto& vec)
{
    return ranges::make_view_closure(
      [&vec](auto&& rng)
      { return detail::transform_fn(std::forward<decltype(rng)>(rng), vec, std::forward<ranges::multiplies>(ranges::multiplies{})); });
}

} // namespace views

int main()
{
    std::array<double, 2> vec{ 20.0, 1.0 };
    std::array<double, 2> scaling_vec{ 2.0, 2.0 };
    std::vector<std::array<double, 2>> poly{ { 3.0, 4.0 }, { 6.0, 9.0 }, { 5.5, 1.25 } };

    auto translated = poly | views::translate(vec) | views::scale(scaling_vec);

    ranges::for_each(translated, [](auto&& point) { std::cout << point << std::endl; });

    return 0;
}