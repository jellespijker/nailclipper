// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <catch2/catch.hpp>

#include <tuple>
#include <vector>
#include <any>

#include "NailClipper/Clipper.h"
#include <curaengine-lite/IntPoint.h>

TEST_CASE("File extension", "[File operations]")
{
    auto p1 = cura::Point {0, 0};
    auto p2 = cura::Point {0, 100};
    auto p3 = cura::Point {200, 0};
    nail::polygon<cura::Point> poly {p1, p2, p3};
}
