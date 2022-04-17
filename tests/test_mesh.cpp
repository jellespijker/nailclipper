// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <catch2/catch.hpp>

#include <NailClipper/Mesh/Mesh.h>

TEST_CASE("Import ASCII STL", "[File operations]")
{
    auto file = std::filesystem::path("/home/peer23peer/big.stl");
    const auto data = nail::mesh::readASCIISTL(file);
    std::string_view data_view{ data };
    nail::Mesh auto mesh = nail::mesh::translateASCIISTL<double>(data_view);
    auto x = 1;
}