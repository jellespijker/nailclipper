// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NailClipper_CLIPPER_H
#define NailClipper_CLIPPER_H

#include <vector>

#include "Concepts.h"

namespace nail
{
template<Point T>
using polygon = std::vector<T>;
}

#endif // NailClipper_CLIPPER_H
