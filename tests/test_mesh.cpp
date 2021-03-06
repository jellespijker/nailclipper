// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include "test_stl.h"

#include <NailClipper/conversion.h>
#include <NailClipper/mesh/mesh.h>
#include <catch2/catch_all.hpp>
#include <filesystem>
#include <range/v3/all.hpp>
#include <source_location>

namespace rg = ranges;
namespace rv = ranges::views;

TEST_CASE("Regex ASCII STL", "[File operations]")
{
    nail::Mesh auto mesh = nail::mesh::translateASCIISTL<double>(stl_short);

    REQUIRE(mesh.size() == 3);
    rg::for_each(mesh, [](auto f) { REQUIRE(f.size() == 3); });

    REQUIRE(mesh[0][0][0] == 90);
    REQUIRE(mesh[0][0][1] == 0);
    REQUIRE(mesh[0][0][2] == 5);
    REQUIRE(mesh[0][1][0] == 88.0333);
    REQUIRE(mesh[0][1][1] == 18.7121);
    REQUIRE(mesh[0][1][2] == 0);
    REQUIRE(mesh[0][2][0] == 88.0333);
    REQUIRE(mesh[0][2][1] == 18.7121);
    REQUIRE(mesh[0][2][2] == -5);
    REQUIRE(mesh[0][0][0] == 90);
    REQUIRE(mesh[0][0][1] == 0);
    REQUIRE(mesh[0][0][2] == 5);
    REQUIRE(mesh[1][0][0] == -88.0333);
    REQUIRE(mesh[1][0][1] == 18.7121);
    REQUIRE(mesh[1][0][2] == 0);
}


TEST_CASE("Import ASCII STL", "[File operations]")
{
    auto resources_path = std::filesystem::path{ std::source_location::current().file_name() }.parent_path().append("resources");
    auto file = resources_path.append("test.stl");
    const auto data = nail::mesh::readASCIISTL(file);
    std::string_view data_view{ data };
    nail::Mesh auto mesh = nail::mesh::translateASCIISTL<double>(data_view);

    REQUIRE(mesh.size() == 116);
    rg::for_each(mesh, [](auto f) { REQUIRE(f.size() == 3); });

    REQUIRE(mesh[0][0][0] == 90);
    REQUIRE(mesh[0][0][1] == 0);
    REQUIRE(mesh[0][0][2] == 5);
    REQUIRE(mesh[0][1][0] == 88.0333);
    REQUIRE(mesh[0][1][1] == 18.7121);
    REQUIRE(mesh[0][1][2] == 0);
    REQUIRE(mesh[0][2][0] == 88.0333);
    REQUIRE(mesh[0][2][1] == 18.7121);
    REQUIRE(mesh[0][2][2] == 5);

    REQUIRE(mesh[14][0][0] == 9.40756);
    REQUIRE(mesh[14][0][1] == 89.507);
    REQUIRE(mesh[14][0][2] == 0);
    REQUIRE(mesh[14][1][0] == -9.40756);
    REQUIRE(mesh[14][1][1] == 89.507);
    REQUIRE(mesh[14][1][2] == 5);
    REQUIRE(mesh[14][2][0] == 9.40756);
    REQUIRE(mesh[14][2][1] == 89.507);
    REQUIRE(mesh[14][2][2] == 5);
}

TEST_CASE("Slice mesh", "[Mesh operations]")
{

    nail::Mesh auto mesh = nail::mesh::translateASCIISTL<double>(stl);
}

TEST_CASE("Mesh to VTU", "[IO operations]")
{
    auto resources_path = std::filesystem::path{ std::source_location::current().file_name() }.parent_path().append("resources");
    auto file = resources_path.append("test.stl");
    const auto data = nail::mesh::readASCIISTL(file);
    std::string_view data_view{ data };
    nail::Mesh auto mesh = nail::mesh::translateASCIISTL<double>(data_view);
    auto vtu = nail::conversion::formatVTU(mesh);
    vtu.save_file("mesh.vtu");
}