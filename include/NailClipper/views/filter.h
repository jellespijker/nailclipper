// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_FILTER_H
#define NAILCLIPPER_FILTER_H

#include "NailClipper/concepts.h"
#include "NailClipper/functional/compare.h"

#include <range/v3/view.hpp>


namespace nail::views
{
namespace detail
{
    [[maybe_unused, nodiscard]] constexpr auto filter_higher_fn(const size_t axis, const Number auto lower_limit)
    {
        return ranges::views::filter([axis, lower_limit](const Point3D auto& point) { return higher(axis, point, lower_limit); });
    }

    [[maybe_unused, nodiscard]] constexpr auto filter_lower_fn(const size_t axis, const Number auto upper_limit)
    {
        return ranges::views::filter([axis, upper_limit](const Point3D auto& point) { return lower(axis, point, upper_limit); });
    }

    [[maybe_unused, nodiscard]] constexpr auto
      filter_between_fn(const size_t axis, const Number auto lower_limit, const Number auto upper_limit)
    {
        return ranges::views::filter([axis, lower_limit, upper_limit](const Point3D auto& point)
                                     { return between(axis, point, lower_limit, upper_limit); });
    }
} // namespace detail

[[maybe_unused, nodiscard]] constexpr auto filter_between(Point auto& vec, auto&& proj)
{
    return ranges::make_view_closure(
      [&vec, &proj](auto&& rng)
      { return detail::filter_between_fn(std::forward<decltype(rng)>(rng), vec, std::forward<decltype(proj)>(proj)); });
}

} // namespace nail::views


#endif // NAILCLIPPER_FILTER_H
