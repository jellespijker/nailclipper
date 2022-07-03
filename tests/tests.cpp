// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <NailClipper/Types.h>
#include <NailClipper/Views/Points.h>
#include <NailClipper/Views/Slice.h>
#include <catch2/catch_all.hpp>
#include <curaengine-lite/Format.h>
#include <curaengine-lite/IntPoint.h>
#include <fmt/ranges.h>
#include <range/v3/all.hpp>
#include <spdlog/spdlog.h>

TEST_CASE("Format IntPoint", "[fmt]")
{
    cura::Point p;
    p.X = 10;
    p.Y = 20;

    auto point_fmt_int = fmt::format("{}", p);
    spdlog::info(point_fmt_int);
    REQUIRE(point_fmt_int == "10, 20");
    auto point_fmt_array = fmt::format("{:a}", p);
    spdlog::info(point_fmt_array);
    REQUIRE(point_fmt_array == "[10, 20]");
}

TEST_CASE("Format polygon", "[fmt]")
{
    cura::Point p1;
    p1.X = 10;
    p1.Y = 20;

    cura::Point p2;
    p2.X = 100;
    p2.Y = 200;

    cura::Point p3;
    p3.X = 150;
    p3.Y = 20;

    cura::Polygon poly;
    poly.add(p1);
    poly.add(p2);
    poly.add(p3);

    auto poly_fmt = fmt::format("{}", poly);
    spdlog::info(poly_fmt);
    REQUIRE(poly_fmt == "10, 20, 100, 200, 150, 20"); // FIXME: this is not the expected output
}

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

TEST_CASE("Point sort", "[polyline]")
{
    using namespace nail;
    using namespace nail::views;
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

TEST_CASE("Slice line", "[polyline]")
{
    using namespace nail;
    using namespace nail::views;
    polyline3d_t<double> l1{ { 5.0, 20.5, 10. }, { 10.0, 20., 20. }, { 15.0, 21.5, 30. } };
    polyline3d_t<double> l_expected{ { 10.0, 20., 20. }, { 5.0, 20.5, 10. }, { 15.0, 21.5, 30. } };

    //    auto x = l1 | slice(0.1); // | ranges::to<polyline3d_t<double>>;
    // spdlog::info(x);
}