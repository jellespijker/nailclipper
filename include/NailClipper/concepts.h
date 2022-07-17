// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_CONCEPTS_H
#define NAILCLIPPER_CONCEPTS_H

#include <concepts/concepts.hpp>
#include <concepts>
#include <ranges>
#include <type_traits>

namespace nail
{
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

template<class T>
concept Line = std::ranges::range<T> && std::ranges::sized_range<T> && std::tuple_size_v<T> == 2
            && (Point2D<typename T::value_type> || Point3D<typename T::value_type>);

template<class T>
concept Polyline = std::ranges::range<T> && (Point2D<typename T::value_type> || Point3D<typename T::value_type>);

template<class T>
concept Polygon = Polyline<T>; // TODO: write concept for close loop polyline

template<class T>
concept Face = std::ranges::range<T> && Point3D<typename T::value_type>;

template<class T>
concept Mesh = std::ranges::range<T> && Face<typename T::value_type>;

template<class T>
concept Cloud = std::ranges::range<T> && Point3D<typename T::value_type>;

template<class T>
concept GeometricData = Polygon<T> || Face<T> || Mesh<T> || Cloud<T>;

template<class T>
concept GeometricCollection = std::ranges::range<T>; // && GeometricData<typename T::value_type>;

} // namespace nail

#endif // NAILCLIPPER_CONCEPTS_H
