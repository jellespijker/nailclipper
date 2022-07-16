// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <array>
#include <concepts>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <range/v3/range/dangling.hpp>
#include <range/v3/view.hpp>
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
    template<class Rng, Point Vec>
    class translate_view : public ranges::view_adaptor<translate_view<Rng, Vec>, Rng>
    {
        friend ranges::range_access;
        Vec vec_;
        class adaptor : public ranges::adaptor_base
        {
            Vec vec_;

          public:
            adaptor() = default;
            adaptor(const Vec& vec) : vec_{ vec } {};

            auto read(ranges::iterator_t<Rng> it) const
            {
                return ranges::views::zip(*it, vec_) | ranges::views::transform([](const auto& pair) { return pair.first + pair.second; });
            }
        };

        [[maybe_unused, nodiscard]] adaptor begin_adaptor() const
        {
            return adaptor{ vec_ };
        }

        [[maybe_unused, nodiscard]] adaptor end_adaptor() const
        {
            return adaptor{ vec_ };
        }

      public:
        translate_view() = default;
        translate_view(Rng&& rng, Vec vec) : translate_view::view_adaptor{ std::forward<Rng>(rng) }, vec_{ std::move(vec) }
        {
        }
    };

    template<class Rng, Point Vec>
    translate_view<Rng, Vec> translate_fn(Rng&& rng, Vec vec)
    {
        return { std::forward<Rng>(rng), std::move(vec) };
    }
} // namespace detail

auto translate(Point auto vec)
{
    return ranges::make_view_closure([vec](auto&& rng) { return detail::translate_fn(std::forward<decltype(rng)>(rng), vec); });
}

} // namespace views

int main()
{
    std::array<double, 2> vec{ 2.0, 1.0 };
    std::vector<std::array<double, 2>> poly{ { 3.0, 4.0 }, { 6.0, 9.0 }, { 5.5, 1.25 } };

    auto translated = poly | views::translate(vec);

    fmt::print("{}", translated);

    return 0;
}