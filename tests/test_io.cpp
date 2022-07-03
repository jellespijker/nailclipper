// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <NailClipper/Conversion.h>
#include <NailClipper/Types.h>
#include <catch2/catch_all.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <pugixml.hpp>
#include <range/v3/view/zip.hpp>
#include <spdlog/spdlog.h>
#include <vector>

TEST_CASE("Write Polygon", "[IO operations]")
{
    auto resources_path = std::filesystem::path{ __FILE__ }.parent_path().append("resources");

    spdlog::set_level(spdlog::level::debug);
    nail::container_3d_t<> polygons;

    nail::polygon3d_t<> l1{ {
                              0,
                              0,
                              0,
                            },
                            { 1, -0.10000000149011612, 0 },
                            { 0.800000011920929, 0.5, 0 },
                            { 1, 1, 0 },
                            { 0.6000000238418579, 1.2000000476837158, 0 },
                            { 0, 0.800000011920929, 0 } };
    nail::polygon3d_t<> l2{ {
                              0,
                              0,
                              1,
                            },
                            { 1, -0.10000000149011612, 1 },
                            { 0.800000011920929, 0.5, 1 },
                            { 1, 1, 1 },
                            { 0.6000000238418579, 1.2000000476837158, 1 },
                            { 0, 0.800000011920929, 1 } };
    nail::polygon3d_t<> l3{ {
                              0,
                              0,
                              3,
                            },
                            { 1, -0.10000000149011612, 3 },
                            { 0.800000011920929, 0.5, 3 },
                            { 1, 1, 3 },
                            { 0.6000000238418579, 1.2000000476837158, 3 },
                            { 0, 0.800000011920929, 3 } };
    polygons.emplace_back(l1);
    polygons.emplace_back(l2);
    polygons.emplace_back(l3);

    auto vtu = nail::conversion::formatVTU(polygons);

    auto vtu_test = pugi::xml_document();
    vtu_test.load_file(resources_path.append("simple_polygon_stack.vtu").string().c_str());
    for (auto&& [first, second] : ranges::view::zip(vtu, vtu_test))
    {
        REQUIRE_THAT(first.name(), Catch::Matchers::Equals(second.name()));
        // TODO: Write complete test
    }
}