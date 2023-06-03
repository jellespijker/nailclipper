// Copyright (c) 2022-2023. Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher


#include <benchmark/benchmark.h>
#include <filesystem>
#include <fmt/ranges.h>
#include <range/v3/all.hpp>
#include <spdlog/spdlog.h>


#include "NailClipper/files/stl.hpp"
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

BENCHMARK_MAIN();