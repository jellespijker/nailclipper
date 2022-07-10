// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_POINTS_H
#define NAILCLIPPER_POINTS_H

#include "NailClipper/Concepts.h"
#include <range/v3/view/filter.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/zip.hpp>
#include <spdlog/spdlog.h>

namespace nail::views
{
struct Axis
{
    static constexpr size_t X = 0;
    static constexpr size_t Y = 1;
    static constexpr size_t Z = 2;
};

[[nodiscard]] inline constexpr auto higher(const size_t axis, const Point3D auto& point, const Number auto lower_limit)
{
    return point[axis] > lower_limit;
}

[[nodiscard]] inline constexpr auto lower(const size_t axis, const Point3D auto& point, const Number auto upper_limit)
{
    return point[axis] < upper_limit;
}

[[nodiscard]] inline constexpr auto
  between(const size_t axis, const Point3D auto& point, const Number auto lower_limit, const Number auto upper_limit)
{
    return higher(axis, point, lower_limit) && lower(axis, point, upper_limit);
}

[[nodiscard]] inline constexpr auto equal(const size_t axis, const Point3D auto& point, const Number auto value)
{
    return point[axis] == value;
}

[[maybe_unused, nodiscard]] constexpr auto filterHigher(const size_t axis, const Number auto lower_limit)
{
    return ranges::views::filter([axis, lower_limit](const Point3D auto& point) { return higher(axis, point, lower_limit); });
}

[[maybe_unused, nodiscard]] constexpr auto filterLower(const size_t axis, const Number auto upper_limit)
{
    return ranges::views::filter([axis, upper_limit](const Point3D auto& point) { return lower(axis, point, upper_limit); });
}

[[maybe_unused, nodiscard]] constexpr auto filterBetween(const size_t axis, const Number auto lower_limit, const Number auto upper_limit)
{
    return ranges::views::filter([axis, lower_limit, upper_limit](const Point3D auto& point)
                                 { return between(axis, point, lower_limit, upper_limit); });
}

[[maybe_unused, nodiscard]] constexpr auto filterEqual(const size_t axis, const Number auto value)
{
    return ranges::views::filter([axis, value](const Point3D auto& point) { return equal(axis, point, value); });
}

[[maybe_unused, nodiscard]] constexpr auto translate(const Point auto& vector, const Point auto& point)
{
    auto translated_point =
      ranges::views::zip(point, vector) | ranges::views::transform([](const auto& pair) { return pair.first + pair.second; });
    return translated_point;
}

[[maybe_unused, nodiscard]] constexpr auto translate(const Point auto& vector, const Polygon auto& polygon)
{
    return polygon | ranges::views::transform([&vector](const auto& point) { return translate(vector, point); });
}

} // namespace nail::views
#endif // NAILCLIPPER_POINTS_H
