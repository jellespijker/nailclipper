// Copyright (c) 2023. UltiMaker & Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher

#ifndef UTILS_TYPES_GEOMETRY_H
#define UTILS_TYPES_GEOMETRY_H

#include <concepts>
#include <string>
#include <type_traits>
#include <utility>

#include <range/v3/range/concepts.hpp>
#include <range/v3/range/operations.hpp>

#include "NailClipper/containers/winding.hpp"
#include "NailClipper/types/generic.hpp"
#include "NailClipper/types/type_traits.hpp"

namespace nail::types
{

template<class T>
concept point2d_named = requires(T point)
{
    { point.X } -> numerical;
    { point.Y } -> numerical;
};

template<class T>
concept point2d_named_lowercase = requires(T point)
{
    { point.x } -> numerical;
    { point.y } -> numerical;
};

template<class T>
concept ranged_point2d = requires(T point)
{
    requires std::tuple_size_v<T> == 2;
    { ranges::get<0>(point) } -> numerical;
    { ranges::get<1>(point) } -> numerical;
};

template<class T>
concept point2d = point2d_named<T> || point2d_named_lowercase<T> || ranged_point2d<T>;

template<class T>
concept point3d_named = requires(T point)
{
    { point.X } -> numerical;
    { point.Y } -> numerical;
    { point.Z } -> numerical;
};

template<class T>
concept point3d_named_lowercase = requires(T point)
{
    { point.x } -> numerical;
    { point.y } -> numerical;
    { point.z } -> numerical;
};

template<class T>
concept ranged_point3d = requires(T point)
{
    requires std::tuple_size_v<T> == 3;
    { ranges::get<0>(point) } -> numerical;
    { ranges::get<1>(point) } -> numerical;
    { ranges::get<2>(point) } -> numerical;
};

template<class T>
concept point3d = point3d_named<T>  || point2d_named_lowercase<T> || ranged_point3d<T>;

template<class T>
concept point_named = point2d_named<T> || point3d_named<T>;

template<class T>
concept point = point2d<T> || point3d<T>;

template<class T>
concept point_ranged = point<T> && ! point2d_named<T> && ! point3d_named<T>;

template<class T>
concept clipper_path = ranges::range<T> && point<typename T::value_type>;

template<class T>
concept clockwise_path = is_cw_v<T>;

template<class T>
concept counter_clockwise_path = is_ccw_v<T>;

template<class T>
concept open_path = ranges::range<T> && closable<T> && point<typename T::value_type> && is_open_v<T>;

template<class T>
concept closed_path = ranges::range<T> && closable<T> && point<typename T::value_type> && is_closed_v<T>;

template<class T>
concept filled_path = closed_path<T> && fillable<T> && is_filled_v<T>;

template<class T>
concept ranged_path = ranges::range<T> && (filled_path<typename T::value_type> || open_path<typename T::value_type> || closed_path<typename T::value_type> || clipper_path<typename T::value_type>);

template<class T>
concept segment = requires(T segment)
{
    requires point<decltype(std::get<0>(segment))>;
    requires point<decltype(std::get<1>(segment))>;
};

template<class T>
concept segment_range = ranges::range<T> && requires(T segment_range)
{
    requires segment<decltype(ranges::front(segment_range))>;
};

template<class T>
concept face = ranges::range<T> && point3d<typename T::value_type>;

template<class T>
concept mesh = ranges::range<T> && face<typename T::value_type>;

} // namespace nail::types

#endif // UTILS_TYPES_GEOMETRY_H