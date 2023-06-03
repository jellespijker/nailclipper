// Copyright (c) 2023. Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher


#include <catch2/catch_all.hpp>

#include "NailClipper/containers/mesh.hpp"
#include "NailClipper/containers/point.hpp"

#include "NailClipper/types/get.hpp"


TEST_CASE("Point construction", "[Containers, Point]")
{
    const nail::point pee1{ 1, 2, 3 };
    const nail::point pee2{ 1, 2 };
    static_assert(nail::types::point3d<decltype(pee1)>);
    static_assert(!nail::types::point3d<decltype(pee2)>);
    static_assert(nail::types::point2d<decltype(pee2)>);
    static_assert(!nail::types::point2d<decltype(pee1)>);


    REQUIRE(std::get<"X">(pee1) == 1);
}

TEST_CASE("Mesh construction", "[Containers, Mesh]")
{
    auto mesh = nail::mesh_t{ { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } };
}