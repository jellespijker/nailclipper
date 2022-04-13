// Copyright (c) 2022 Jelle Spijker
// # NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_CONCEPTS_H
#define NAILCLIPPER_CONCEPTS_H

#include <concepts>

namespace nail
{
template<typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template<typename T>
concept PointXY = requires(T p) {
    requires Number<decltype(p.X)>;
    requires Number<decltype(p.Y)>;
};

template<typename T>
concept Pointxy = requires(T p)
{
    requires Number<decltype(p.x)>;
    requires Number<decltype(p.y)>;
};

template<typename T>
concept Point = PointXY<T> || Pointxy<T>;

} // namespace nail

#endif // NAILCLIPPER_CONCEPTS_H
