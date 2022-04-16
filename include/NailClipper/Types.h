// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_TYPES_H
#define NAILCLIPPER_TYPES_H

#include <array>

#include "NailClipper/Concepts.h"

namespace nail
{
template<Number T>
using point2d = std::array<T, 2>;

template<Number T>
using point3d = std::array<T, 3>;

template<Number T>
using triangle = std::array<point3d<T>, 3>;

}


#endif // NAILCLIPPER_TYPES_H
