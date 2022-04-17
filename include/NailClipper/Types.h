// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_TYPES_H
#define NAILCLIPPER_TYPES_H

#include <vector>
#include <array>

#include "NailClipper/Concepts.h"

namespace nail
{
template<Number T>
using point2d_t = std::array<T, 2>;

template<Number T>
using point3d_t = std::array<T, 3>;

#ifdef WITH_MESH
template<Number T>
using face_t = std::vector<point3d_t<T>>;

template<Number T>
using mesh_t = std::vector<face_t<T>>;
#endif
}


#endif // NAILCLIPPER_TYPES_H
