// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_CONCEPTS_H
#define NAILCLIPPER_CONCEPTS_H

#include <concepts>
#include <type_traits>

namespace nail
{
template<typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template<typename T>
concept Arithmetic = requires(T p)
{
    { p + p } -> std::same_as<T>;
    { p - p } -> std::same_as<T>;
    { p * p } -> std::same_as<T>;
    { p / p } -> std::same_as<T>;
};

template<typename T>
concept BasePointXY = requires(T p) {
    requires Number<decltype(p.X)>;
    requires Number<decltype(p.Y)>;
};

template<typename T>
concept BasePointxy = requires(T p)
{
    requires Number<decltype(p.x)>;
    requires Number<decltype(p.y)>;
};

template<typename T>
concept BasePoint2DContainer = std::is_bounded_array_v<T> && std::extent_v<T> == 2 && requires(T p)
{
    requires Number<decltype(p[0])>;
};

template<typename T>
concept BasePoint2D = BasePointXY<T> || BasePointxy<T> || BasePoint2DContainer<T>;

template<typename T>
concept Point2D = Arithmetic<T> && BasePoint2D<T>;

template<typename T>
concept BasePointXYZ = BasePointXY<T> && requires(T p)
{
    requires Number<decltype(p.Z)>;
};

template<typename T>
concept BasePointxyz = BasePointxy<T> && requires(T p)
{
    requires Number<decltype(p.z)>;
};

template<typename T>
concept BasePoint3DContainer = std::is_bounded_array_v<T> && std::extent_v<T> == 3 && requires(T p)
{
    requires Number<decltype(p[0])>;
};

template<typename T>
concept BasePoint3D = BasePointXYZ<T> || BasePointxyz<T> || BasePoint3DContainer<T> ;

template<typename T>
concept Point3D = Arithmetic<T> && BasePoint3D<T>;

} // namespace nail

#endif // NAILCLIPPER_CONCEPTS_H
