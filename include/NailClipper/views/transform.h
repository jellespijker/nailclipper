// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_TRANSFORM_H
#define NAILCLIPPER_TRANSFORM_H

#include "NailClipper/concepts.h"

#include <range/v3/view.hpp>

namespace nail::views
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

            [[maybe_unused, nodiscard]] inline constexpr auto read(ranges::iterator_t<Rng> it) const
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

constexpr auto transform(Point auto& vec, auto&& proj)
{
    return ranges::make_view_closure(
      [&vec, &proj](auto&& rng)
      { return detail::transform_fn(std::forward<decltype(rng)>(rng), vec, std::forward<decltype(proj)>(proj)); });
}

} // namespace nail::views

#endif // NAILCLIPPER_TRANSFORM_H
