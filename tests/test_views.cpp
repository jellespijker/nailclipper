// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <NailClipper/types.h>
#include <NailClipper/views/scale.h>
#include <NailClipper/views/translate.h>
#include <catch2/catch_all.hpp>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <range/v3/all.hpp>

TEST_CASE("Simple double 2D polygons", "[polygon][views]")
{
    using namespace nail;
    using namespace nail::views;
    polygon2d_t<> poly{ { 5.0, 20.5 }, { 10.0, 20. }, { 15.0, 21.5 } };

    point2d_t<> translate_vector2d{ 1., 2. };
    polygon2d_t<> translate_expected{ { 6.5, 24.5 }, { 11.5, 24. }, { 16.5, 25.5 } };
    //    polygon2d_t<> translate_expected{ { 6.0, 22.5 }, { 11.0, 22. }, { 16.0, 23.5 } };

    point2d_t<> scale_vector2d{ 0.5, 2. };
    polygon2d_t<> scale_expected{ { 2.5, 41.0 }, { 5.0, 40.0 }, { 7.5, 43.0 } };

    polygon2d_t<> translate_scale_expected{ { 3.0, 45.0 }, { 5.5, 44.0 }, { 8.0, 47.0 } };

    SECTION("Translate")
    {
        auto translated_polygon = poly | translate(translate_vector2d) | ranges::to_vector;
        auto t2 = translated_polygon | translate(scale_vector2d);
        fmt::print("{}\n", translated_polygon);
        for (auto [point, point_e] : ranges::views::zip(translated_polygon, t2))
        {
            for (auto [p, p_e] : ranges::views::zip(point, point_e))
            {
                REQUIRE(p == p_e);
            }
        }
    }

    //    SECTION("Scale")
    //    {
    //        auto scaled_polygon = poly | scale(scale_vector2d);
    //        for (auto [point, point_e] : ranges::views::zip(scaled_polygon, scale_expected))
    //        {
    //            for (auto [p, p_e] : ranges::views::zip(point, point_e))
    //            {
    //                REQUIRE(p == p_e);
    //            }
    //        }
    //    }

    //    SECTION("Composite Translate and Scale")
    //    {
    ////        auto translated_scale_polygon = poly | translate(translate_vector2d) | scale(scale_vector2d);
    //        auto t1 = poly | translate(translate_vector2d);
    //        fmt::print("{}\n", t1);
    //        fmt::print("{}\n", t1);
    //        auto t2 = t1 | scale(scale_vector2d);
    //        fmt::print("{}\n", t2);
    //        fmt::print("{}\n", t2);
    //        for (auto [point, point_e] : ranges::views::zip(t2, translate_scale_expected))
    //        {
    //            for (auto [p, p_e] : ranges::views::zip(point, point_e))
    //            {
    //                REQUIRE(p == p_e);
    //            }
    //        }
    //    }
}

TEST_CASE("Simple int64 2D polygons", "[polygon][views]")
{
    using namespace nail;
    using namespace nail::views;
    polygon2d_t<int64_t> poly{ { 5, 20 }, { 10, 20 }, { 15, 22 } };

    point2d_t<int64_t> translate_vector2d{ 10, 2 };
    polygon2d_t<int64_t> translate_expected{ { 15, 22 }, { 20, 22 }, { 25, 24 } };

    point2d_t<int64_t> scale_vector2d{ 1, 2 };
    polygon2d_t<int64_t> scale_expected{ { 5, 40 }, { 10, 40 }, { 15, 44 } };

    SECTION("Translate")
    {
        auto translated_polygon = poly | translate(translate_vector2d);
        for (auto [point, point_e] : ranges::views::zip(translated_polygon, translate_expected))
        {
            for (auto [p, p_e] : ranges::views::zip(point, point_e))
            {
                REQUIRE(p == p_e);
            }
        }
    }

    SECTION("Scale")
    {
        auto scaled_polygon = poly | scale(scale_vector2d);
        for (auto [point, point_e] : ranges::views::zip(scaled_polygon, scale_expected))
        {
            for (auto [p, p_e] : ranges::views::zip(point, point_e))
            {
                REQUIRE(p == p_e);
            }
        }
    }
}
