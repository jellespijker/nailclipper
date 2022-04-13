// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <benchmark/benchmark.h>
#include "curaengine-lite/polygon.h"
#include "NailClipper/Clipper.h"


static void BM_clipper_polygonCreation(benchmark::State& state)
{
    auto p1 = cura::Point {0, 0};
    auto p2 = cura::Point {0, 100};
    auto p3 = cura::Point {200, 0};
    ClipperLib::Path path {p1, p2, p3};;
    for (auto _ : state) cura::Polygon poly { path };
}
BENCHMARK(BM_clipper_polygonCreation);

static void BM_nail_polygonCreation(benchmark::State& state)
{
    auto p1 = cura::Point {0, 0};
    auto p2 = cura::Point {0, 100};
    auto p3 = cura::Point {200, 0};
    static_assert(std::is_integral<decltype(p1.X)>::value, "Integral required.");
//    for (auto _ : state) nail::polygon<ClipperLib::IntPoint> poly { p1, p2, p3 };
}
BENCHMARK(BM_nail_polygonCreation);

BENCHMARK_MAIN();