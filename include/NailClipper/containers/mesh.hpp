// Copyright (c) 2023. Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_CONTAINERS_MESH_HPP
#define NAILCLIPPER_CONTAINERS_MESH_HPP

#include <vector>


#include "NailClipper/containers/point.hpp"
#include "NailClipper/types/generic.hpp"

namespace nail
{

template<types::numerical T = std::int64_t>
using face_t = std::vector<point<T, T, T>>;

template<types::numerical T = std::int64_t>
using mesh_t = std::vector<face_t<T>>;

} // namespace nail

#endif // NAILCLIPPER_CONTAINERS_MESH_HPP
