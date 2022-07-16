// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <NailClipper/Conversion.h>
#include <NailClipper/Types.h>
#include <NailClipper/Views/Points.h>
#include <catch2/catch_all.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <pugixml.hpp>
#include <range/v3/all.hpp>
#include <range/v3/view/zip.hpp>
#include <spdlog/spdlog.h>
#include <vector>

TEST_CASE("Write Polygon", "[IO operations]")
{
    auto resources_path = std::filesystem::path{ __FILE__ }.parent_path().append("resources");

    spdlog::set_level(spdlog::level::debug);

    nail::polygon3d_t<> poly{ {
                                0,
                                0,
                                0,
                              },
                              { 1, -0.10000000149011612, 0 },
                              { 0.800000011920929, 0.5, 0 },
                              { 1, 1, 0 },
                              { 0.6000000238418579, 1.2000000476837158, 0 },
                              { 0, 0.800000011920929, 0 } };


    //    auto translated_polygons = ranges::view::linear_distribute(0.0, 100.0, 50)
    //                             | ranges::view::transform(
    //                                 [&poly](const auto& z)
    //                                 {
    //                                     auto translated_polygon = nail::views::translate(nail::point3d_t<>{ 0., z, z }, poly);
    //                                     return translated_polygon;
    //                                 });
    //
    //    auto vtu = nail::conversion::formatVTU(translated_polygons);
    //    vtu.save_file("test.vtu");
    //
    //    auto vtu_test = pugi::xml_document();
    //    vtu_test.load_file(resources_path.append("simple_polygon_stack.vtu").string().c_str());
    //    for (auto&& [first, second] : ranges::view::zip(vtu, vtu_test))
    //    {
    //        REQUIRE_THAT(first.name(), Catch::Matchers::Equals(second.name()));
    //        // TODO: Write complete test
    //    }
}