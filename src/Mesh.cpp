// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <array>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string_view>
#include <utility>
#include <vector>

#include <ctre.hpp>
#include <range/v3/all.hpp>
#include <spdlog/spdlog.h>

#include "NailClipper/Mesh/Mesh.h"
#include "NailClipper/Types.h"


using namespace std::literals;

namespace nail::mesh
{

Mesh auto importMesh(const std::filesystem::path& filename, const FileTypes& file_types)
{
    if (! exists(filename))
    {
        spdlog::error("File {} doesn't exist", filename.string());
        return mesh_t<double>{};
    }
    spdlog::info("Reading file {}", filename.string());

    if (file_types != FileTypes::STL_ASCII)
    {
        // TODO: implement autodetect for now assume ASCII STL
        spdlog::error("Not yet implemented file type {}", static_cast<int>(file_types));
    }
    auto raw_data{ readASCIISTL(filename) };
    std::string_view data_view{ raw_data };
    return mesh_t<double>{};
}

std::string readASCIISTL(const std::filesystem::path& filename)
{
    std::ifstream file{ filename };
    std::string raw_data;
    if (file.is_open())
    {
        raw_data.assign((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    }
    else
    {
        spdlog::error("Could not open {}", filename.string());
        return "";
    }
    return raw_data;
}

} // namespace nail::mesh