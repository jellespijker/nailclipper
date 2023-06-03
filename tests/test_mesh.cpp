// Copyright (c) 2022-2023. Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher

#include <filesystem>
#include <source_location>

#include <catch2/catch_all.hpp>
#include <range/v3/all.hpp>

#include "test_stl.h"

#include "NailClipper/containers/mesh.hpp"
#include "NailClipper/files/stl.hpp"

namespace rg = ranges;

TEST_CASE("Regex ASCII STL", "[File operations]")
{
//    auto mesh = nail::files::details::translate_asciistl<nail::mesh_t<>>(stl_short).value();
//
//    REQUIRE(mesh.size() == 3);
//    rg::for_each(mesh, [](auto f) { REQUIRE(f.size() == 3); });
//
//    REQUIRE(mesh[0][0][0] == 90);
//    REQUIRE(mesh[0][0][1] == 0);
//    REQUIRE(mesh[0][0][2] == 5);
//    REQUIRE(mesh[0][1][0] == 88.0333);
//    REQUIRE(mesh[0][1][1] == 18.7121);
//    REQUIRE(mesh[0][1][2] == 0);
//    REQUIRE(mesh[0][2][0] == 88.0333);
//    REQUIRE(mesh[0][2][1] == 18.7121);
//    REQUIRE(mesh[0][2][2] == -5);
//    REQUIRE(mesh[0][0][0] == 90);
//    REQUIRE(mesh[0][0][1] == 0);
//    REQUIRE(mesh[0][0][2] == 5);
//    REQUIRE(mesh[1][0][0] == -88.0333);
//    REQUIRE(mesh[1][0][1] == 18.7121);
//    REQUIRE(mesh[1][0][2] == 0);
}


TEST_CASE("Import ASCII STL", "[File operations]")
{
//    auto resources_path = std::filesystem::path{ std::source_location::current().file_name() }.parent_path().append("resources");
//    auto file = resources_path.append("test.stl");
//    const auto mesh = nail::files::import_mesh<nail::mesh_t<>>(file).value();
//
//    REQUIRE(mesh.size() == 116);
//    rg::for_each(mesh, [](auto f) { REQUIRE(f.size() == 3); });
//
//    REQUIRE(mesh[0][0][0] == 90);
//    REQUIRE(mesh[0][0][1] == 0);
//    REQUIRE(mesh[0][0][2] == 5);
//    REQUIRE(mesh[0][1][0] == 88.0333);
//    REQUIRE(mesh[0][1][1] == 18.7121);
//    REQUIRE(mesh[0][1][2] == 0);
//    REQUIRE(mesh[0][2][0] == 88.0333);
//    REQUIRE(mesh[0][2][1] == 18.7121);
//    REQUIRE(mesh[0][2][2] == 5);
//
//    REQUIRE(mesh[14][0][0] == 9.40756);
//    REQUIRE(mesh[14][0][1] == 89.507);
//    REQUIRE(mesh[14][0][2] == 0);
//    REQUIRE(mesh[14][1][0] == -9.40756);
//    REQUIRE(mesh[14][1][1] == 89.507);
//    REQUIRE(mesh[14][1][2] == 5);
//    REQUIRE(mesh[14][2][0] == 9.40756);
//    REQUIRE(mesh[14][2][1] == 89.507);
//    REQUIRE(mesh[14][2][2] == 5);
}
