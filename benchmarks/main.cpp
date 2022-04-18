// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <benchmark/benchmark.h>

#include <fmt/ranges.h>
#include <spdlog/spdlog.h>

#include "curaengine-lite/polygon.h"

#include "NailClipper//Views/Points.h"
#include "NailClipper/Clipper.h"
#include <range/v3/all.hpp>

static void bmClipperPolygonCreation(benchmark::State& state)
{
    auto p1 = cura::Point{ 0, 0 };
    auto p2 = cura::Point{ 0, 100 };
    auto p3 = cura::Point{ 200, 0 };
    ClipperLib::Path path{ p1, p2, p3 };
    for (auto _ : state) cura::Polygon poly{ path };
}
BENCHMARK(bmClipperPolygonCreation);

static void bmPolygonSort(benchmark::State& state)
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
BENCHMARK(bmPolygonSort);

static void bmPolygonFilter(benchmark::State& state)
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
        auto x0 = l1 | nail::views::filterBetween(nail::views::Axis::Y, 5, 10) | ranges::to<polyline3d_t<double>>();
        benchmark::DoNotOptimize(x0);
        auto x1 = l1 | nail::views::filterBetween(nail::views::Axis::Y, 10, 15) | ranges::to<polyline3d_t<double>>();
        benchmark::DoNotOptimize(x1);
        auto x2 = l1 | nail::views::filterBetween(nail::views::Axis::Y, 15, 20) | ranges::to<polyline3d_t<double>>();
        benchmark::DoNotOptimize(x2);
    }
}
BENCHMARK(bmPolygonFilter);

static void bmPolygonFilterAfterSort(benchmark::State& state)
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
        ranges::sort(l1, {}, [](auto p) { return p[nail::views::Axis::Y]; });
        auto x0 = l1 | nail::views::filterBetween(nail::views::Axis::Y, 5, 10) | ranges::to<polyline3d_t<double>>();
        benchmark::DoNotOptimize(x0);
        auto x1 = l1 | nail::views::filterBetween(nail::views::Axis::Y, 10, 15) | ranges::to<polyline3d_t<double>>();
        benchmark::DoNotOptimize(x1);
        auto x2 = l1 | nail::views::filterBetween(nail::views::Axis::Y, 15, 20) | ranges::to<polyline3d_t<double>>();
        benchmark::DoNotOptimize(x2);
    }
}
BENCHMARK(bmPolygonFilterAfterSort);

#ifdef WITH_MESH

#include "NailClipper/Mesh/Mesh.h"
#include "test_stl.h"

static void bmReadASCIISTL(benchmark::State& state)
{
    auto file = std::filesystem::current_path().append("test.stl");
    for (auto _ : state) const auto data = nail::mesh::readASCIISTL(file);
}
BENCHMARK(bmReadASCIISTL);

static void bmTranslateASCIISTL(benchmark::State& state)
{
    for (auto _ : state) nail::Mesh auto mesh = nail::mesh::translateASCIISTL<double>(stl);
}
BENCHMARK(bmTranslateASCIISTL);

static void bmImportASCIISTL(benchmark::State& state)
{
    spdlog::set_level(spdlog::level::off);
    auto file = std::filesystem::current_path().append("test.stl");
    for (auto _ : state) nail::Mesh auto mesh = nail::mesh::importMesh<double>(file, nail::mesh::FileTypes::STL_ASCII);
}
BENCHMARK(bmImportASCIISTL);

#endif

BENCHMARK_MAIN();