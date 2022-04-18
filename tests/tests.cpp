// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <catch2/catch.hpp>

#include <NailClipper/Clipper.h>
#include <NailClipper/Views/Points.h>

#include <range/v3/all.hpp>

#include <fmt/ranges.h>
#include <spdlog/spdlog.h>

TEST_CASE("Point translation", "[point]")
{
    using namespace nail;
    REQUIRE(true);
}

TEST_CASE("Point comparison", "[point]")
{
    using namespace nail;
    using namespace nail::views;
    point3d_t<double> p1{ 10.0, 20., 30. };
    point3d_t<int> p2{ 10, 20, 30 };
    polyline3d_t<double> l1{ { 5.0, 20.5, 10. }, { 10.0, 20., 20. }, { 15.0, 21.5, 30. } };

    auto x = l1 | filterBetween(Axis::Z, 19., 21.) | ranges::to<polyline3d_t<double>>();
    REQUIRE(x[0][0] == 10.0);
    REQUIRE(x[0][1] == 20.0);
    REQUIRE(x[0][2] == 20.0);
}

TEST_CASE("Point sort", "[point]")
{
    using namespace nail;
    using namespace nail::views;
    point3d_t<double> p1{ 10.0, 20., 30. };
    point3d_t<int> p2{ 10, 20, 30 };
    polyline3d_t<double> l1{ { 5.0, 20.5, 10. }, { 10.0, 20., 20. }, { 15.0, 21.5, 30. } };
    polyline3d_t<double> l_expected{ { 10.0, 20., 20. }, { 5.0, 20.5, 10. }, { 15.0, 21.5, 30. } };

    ranges::sort(l1, {}, [](auto p) { return p[1]; });
    for (auto [p1, p2] : ranges::views::zip(l1, l_expected))
    {
        REQUIRE(p1[0] == p2[0]);
        REQUIRE(p1[1] == p2[1]);
        REQUIRE(p1[2] == p2[2]);
    }
}