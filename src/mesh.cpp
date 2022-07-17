// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include "NailClipper/mesh/mesh.h"

#include <fstream>
#include <ranges>
#include <spdlog/spdlog.h>
#include <string_view>


using namespace std::literals;

namespace nail::mesh
{

[[nodiscard]] std::string read_asciistl(const std::filesystem::path& filename) noexcept
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