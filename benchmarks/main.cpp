// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <benchmark/benchmark.h>

#include <spdlog/spdlog.h>

#include "curaengine-lite/polygon.h"

#include "NailClipper/Clipper.h"

static void bmClipperPolygonCreation(benchmark::State& state)
{
    auto p1 = cura::Point{ 0, 0 };
    auto p2 = cura::Point{ 0, 100 };
    auto p3 = cura::Point{ 200, 0 };
    ClipperLib::Path path{ p1, p2, p3 };
    for (auto _ : state) cura::Polygon poly{ path };
}
BENCHMARK(bmClipperPolygonCreation);


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