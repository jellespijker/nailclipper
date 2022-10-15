// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <NailClipper/types.h>
#include <NailClipper/views/filter.h>
#include <benchmark/benchmark.h>
#include <curaengine-lite/polygon.h>
#include <filesystem>
#include <fmt/ranges.h>
#include <range/v3/all.hpp>
#include <spdlog/spdlog.h>

static void bm_clipper_polygon_creation(benchmark::State& state)
{
    auto p1 = cura::Point{ 0, 0 };
    auto p2 = cura::Point{ 0, 100 };
    auto p3 = cura::Point{ 200, 0 };
    ClipperLib::Path path{ p1, p2, p3 };
    for (auto _ : state)
    {
        cura::Polygon poly{ path };
    }
}
BENCHMARK(bm_clipper_polygon_creation);

static void bm_polygon_sort(benchmark::State& state)
{
    using namespace nail;
    polyline3d_t<double> l1{ { 5.0, 20.5, 10. },   { 10.0, 20., 20. },   { 15.0, 21.5, 30. },  { 5.0, 30.5, 10. },   { 10.0, 1., 20. },
                             { 15.0, 21., 30. },   { 5.0, 1.5, 10. },    { 10.0, 5., 20. },    { 15.0, 6, 30. },     { 5.0, 20.5, 10. },
                             { 10.0, 20., 20. },   { 15.0, 21.5, 30. },  { 5.0, 30.5, 10. },   { 10.0, 1., 20. },    { 15.0, 21., 30. },
                             { 5.0, 1.5, 10. },    { 10.0, 5324., 20. }, { 15.0, 4, 30. },     { 5.0, 20.5, 10. },   { 10.0, 20., 20. },
                             { 15.0, 21.5, 30. },  { 5.0, 32, 10. },     { 10.0, 2.3, 20. },   { 15.0, 21., 30. },   { 5.0, 1.57, 10. },
                             { 10.0, 5.213, 20. }, { 15.0, 7, 30. },     { 5.0, 20.5, 10. },   { 10.0, 20., 20. },   { 15.0, 21.5, 30. },
                             { 5.0, 30.5, 10. },   { 10.0, 1., 20. },    { 15.0, 21., 30. },   { 5.0, 1.5, 10. },    { 10.0, 5., 20. },
                             { 15.0, 6, 30. },     { 5.0, 20.5, 10. },   { 10.0, 20., 20. },   { 15.0, 21.5, 30. },  { 5.0, 30.5, 10. },
                             { 10.0, 1., 20. },    { 15.0, 21., 30. },   { 5.0, 1.5, 10. },    { 10.0, 5324., 20. }, { 15.0, 4, 30. },
                             { 5.0, 20.5, 10. },   { 10.0, 20., 20. },   { 15.0, 21.5, 30. },  { 5.0, 32, 10. },     { 10.0, 2.3, 20. },
                             { 15.0, 21., 30. },   { 5.0, 1.57, 10. },   { 10.0, 5.213, 20. }, { 15.0, 7, 30. } };
    for (auto _ : state)
    {
        ranges::sort(l1, {}, [](auto p) { return p[1]; });
    }
}
BENCHMARK(bm_polygon_sort);

static void bm_polygon_filter(benchmark::State& state)
{
    using namespace nail;
    polyline3d_t<double> l1{ { 5.0, 20.5, 10. },   { 10.0, 20., 20. },   { 15.0, 21.5, 30. },  { 5.0, 30.5, 10. },   { 10.0, 1., 20. },
                             { 15.0, 21., 30. },   { 5.0, 1.5, 10. },    { 10.0, 5., 20. },    { 15.0, 6, 30. },     { 5.0, 20.5, 10. },
                             { 10.0, 20., 20. },   { 15.0, 21.5, 30. },  { 5.0, 30.5, 10. },   { 10.0, 1., 20. },    { 15.0, 21., 30. },
                             { 5.0, 1.5, 10. },    { 10.0, 5324., 20. }, { 15.0, 4, 30. },     { 5.0, 20.5, 10. },   { 10.0, 20., 20. },
                             { 15.0, 21.5, 30. },  { 5.0, 32, 10. },     { 10.0, 2.3, 20. },   { 15.0, 21., 30. },   { 5.0, 1.57, 10. },
                             { 10.0, 5.213, 20. }, { 15.0, 7, 30. },     { 5.0, 20.5, 10. },   { 10.0, 20., 20. },   { 15.0, 21.5, 30. },
                             { 5.0, 30.5, 10. },   { 10.0, 1., 20. },    { 15.0, 21., 30. },   { 5.0, 1.5, 10. },    { 10.0, 5., 20. },
                             { 15.0, 6, 30. },     { 5.0, 20.5, 10. },   { 10.0, 20., 20. },   { 15.0, 21.5, 30. },  { 5.0, 30.5, 10. },
                             { 10.0, 1., 20. },    { 15.0, 21., 30. },   { 5.0, 1.5, 10. },    { 10.0, 5324., 20. }, { 15.0, 4, 30. },
                             { 5.0, 20.5, 10. },   { 10.0, 20., 20. },   { 15.0, 21.5, 30. },  { 5.0, 32, 10. },     { 10.0, 2.3, 20. },
                             { 15.0, 21., 30. },   { 5.0, 1.57, 10. },   { 10.0, 5.213, 20. }, { 15.0, 7, 30. } };
    for (auto _ : state)
    {
        //        auto x0 = l1 | nail::views::filter_between(nail::views::Axis::Y, 5, 10) | ranges::to<polyline3d_t<double>>();
        //        benchmark::DoNotOptimize(x0);
        //        auto x1 = l1 | nail::views::filter_between(nail::views::Axis::Y, 10, 15) | ranges::to<polyline3d_t<double>>();
        //        benchmark::DoNotOptimize(x1);
        //        auto x2 = l1 | nail::views::filter_between(nail::views::Axis::Y, 15, 20) | ranges::to<polyline3d_t<double>>();
        //        benchmark::DoNotOptimize(x2);
    }
}
BENCHMARK(bm_polygon_filter);

static void bm_polygon_filter_after_sort(benchmark::State& state)
{
    using namespace nail;
    polyline3d_t<double> l1{ { 5.0, 20.5, 10. },   { 10.0, 20., 20. },   { 15.0, 21.5, 30. },  { 5.0, 30.5, 10. },   { 10.0, 1., 20. },
                             { 15.0, 21., 30. },   { 5.0, 1.5, 10. },    { 10.0, 5., 20. },    { 15.0, 6, 30. },     { 5.0, 20.5, 10. },
                             { 10.0, 20., 20. },   { 15.0, 21.5, 30. },  { 5.0, 30.5, 10. },   { 10.0, 1., 20. },    { 15.0, 21., 30. },
                             { 5.0, 1.5, 10. },    { 10.0, 5324., 20. }, { 15.0, 4, 30. },     { 5.0, 20.5, 10. },   { 10.0, 20., 20. },
                             { 15.0, 21.5, 30. },  { 5.0, 32, 10. },     { 10.0, 2.3, 20. },   { 15.0, 21., 30. },   { 5.0, 1.57, 10. },
                             { 10.0, 5.213, 20. }, { 15.0, 7, 30. },     { 5.0, 20.5, 10. },   { 10.0, 20., 20. },   { 15.0, 21.5, 30. },
                             { 5.0, 30.5, 10. },   { 10.0, 1., 20. },    { 15.0, 21., 30. },   { 5.0, 1.5, 10. },    { 10.0, 5., 20. },
                             { 15.0, 6, 30. },     { 5.0, 20.5, 10. },   { 10.0, 20., 20. },   { 15.0, 21.5, 30. },  { 5.0, 30.5, 10. },
                             { 10.0, 1., 20. },    { 15.0, 21., 30. },   { 5.0, 1.5, 10. },    { 10.0, 5324., 20. }, { 15.0, 4, 30. },
                             { 5.0, 20.5, 10. },   { 10.0, 20., 20. },   { 15.0, 21.5, 30. },  { 5.0, 32, 10. },     { 10.0, 2.3, 20. },
                             { 15.0, 21., 30. },   { 5.0, 1.57, 10. },   { 10.0, 5.213, 20. }, { 15.0, 7, 30. } };
    for (auto _ : state)
    {
        //        ranges::sort(l1, {}, [](auto p) { return p[nail::views::Axis::Y]; });
        //        auto x0 = l1 | nail::views::filter_between(nail::views::Axis::Y, 5, 10) | ranges::to<polyline3d_t<double>>();
        //        benchmark::DoNotOptimize(x0);
        //        auto x1 = l1 | nail::views::filter_between(nail::views::Axis::Y, 10, 15) | ranges::to<polyline3d_t<double>>();
        //        benchmark::DoNotOptimize(x1);
        //        auto x2 = l1 | nail::views::filter_between(nail::views::Axis::Y, 15, 20) | ranges::to<polyline3d_t<double>>();
        //        benchmark::DoNotOptimize(x2);
    }
}
BENCHMARK(bm_polygon_filter_after_sort);

#ifdef WITH_MESH

#include "NailClipper/mesh/mesh.h"
#include "test_stl.h"

static void bm_read_asciistl(benchmark::State& state)
{
    auto file = std::filesystem::current_path().append("test.stl");
    for (auto _ : state)
    {
        //        const auto data = nail::mesh::readASCIISTL(file);
    }
}
BENCHMARK(bm_read_asciistl);

static void bm_translate_asciistl(benchmark::State& state)
{
    for (auto _ : state)
    {
        //        nail::Mesh auto mesh = nail::mesh::translateASCIISTL<double>(stl);
    }
}
BENCHMARK(bm_translate_asciistl);

static void bm_import_asciistl(benchmark::State& state)
{
    spdlog::set_level(spdlog::level::off);
    auto file = std::filesystem::current_path().append("test.stl");
    for (auto _ : state)
    {
        //        nail::Mesh auto mesh = nail::mesh::importMesh<double>(file, nail::mesh::FileTypes::STL_ASCII);
    }
}
BENCHMARK(bm_import_asciistl);

#endif

BENCHMARK_MAIN();