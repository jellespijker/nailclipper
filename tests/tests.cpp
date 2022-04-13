// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <catch2/catch.hpp>

#include <tuple>
#include <vector>
#include <any>

#include "NailClipper//Clipper.h"

unsigned int Factorial(unsigned int number) // NOLINT(misc-no-recursion)
{
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("File extension", "[File operations]")
{
    using polygon_t = std::vector<std::tuple<int, int, int>>;
    using property_t = std::vector<std::any>
    std::vector<std::tuple<int, int, int>> polygon{ { 0, 3, 4 }, { 5, 7, 9 }, { 50, 3, 9 } };
    std::vector<std::tuple<int, int, int>> polygon2{ { 0, 3, 4 }, { 5, 7, 9 }, { 50, 3, 9 } };
    std::vector<std::tuple<int, int, int>> polygon3{ { 0, 3, 4 }, { 5, 7, 9 }, { 50, 3, 9 } };

    auto data = vtk::VTKData<polygon_t>

//    auto data = std::make_shared<vtk::VTKData>(vtk::DatasetCategory::UNSTRUCTURED_GRID);
//    vtk::VTKWriter writer{ data, vtk::XMLFileFormats::SERIAL };
//    writer.save("blaat");
}

TEST_CASE("Factorials are computed", "[factorial]")
{
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}