// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_TYPES_H
#define NAILCLIPPER_TYPES_H

#include <array>
#include <vector>

#include "NailClipper/Concepts.h"

namespace nail
{
template<Number T = double>
using point2d_t = std::array<T, 2>;

template<Number T = double>
using point3d_t = std::array<T, 3>;

template<Number T = double>
using polyline2d_t = std::vector<point2d_t<T>>;

template<Number T = double>
using polygon2d_t = std::vector<point2d_t<T>>;

template<Number T = double>
using polyline3d_t = std::vector<point3d_t<T>>;

template<Number T = double>
using polygon3d_t = std::vector<point3d_t<T>>;

template<Number T = double>
using container_2d_t = std::vector<polygon2d_t<T>>;

template<Number T = double>
using container_3d_t = std::vector<polygon3d_t<T>>;

#ifdef WITH_MESH
template<Number T = double>
using face_t = std::vector<point3d_t<T>>;

template<Number T = double>
using mesh_t = std::vector<face_t<T>>;
#endif
} // namespace nail


#endif // NAILCLIPPER_TYPES_H
