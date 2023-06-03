// Copyright (c) 2022-2023. Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_MESH_H
#define NAILCLIPPER_MESH_H

#include <filesystem>
#include <fstream>
#include <optional>
#include <string_view>

#include <ctre.hpp>
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/chunk.hpp>
#include <range/v3/view/transform.hpp>
#include <spdlog/spdlog.h>

#include "NailClipper/files/filetypes.hpp"
#include "NailClipper/types/geometry.hpp"

namespace nail::files
{
namespace details
{
template<types::numerical T>
[[nodiscard]] constexpr types::numerical auto to_number(std::string_view view) noexcept
{
    T number;
    std::from_chars(view.begin(), view.end(), number);
    return number;
}

template<types::mesh T>
[[nodiscard]] constexpr auto translate_asciistl(std::string_view data)
{
    using mesh_t = T;
    using point3d_t = typename mesh_t::value_type::value_type;
    using coord_t = typename point3d_t::value_type;

    auto vertexes = ctre::multiline_range<R"(\s+vertex\s([\-\d]*\.?\d*)\s([\-\d]*\.?\d*)\s([\-\d]*\.?\d*))">(data);
    return vertexes | ranges::views::transform([](auto point) { return point3d_t{ to_number<coord_t>(get<1>(point)), to_number<coord_t>(get<2>(point)), to_number<coord_t>(get<3>(point)) }; }) | ranges::views::chunk(3) | ranges::to<mesh_t>;
}

[[nodiscard]] std::optional<std::string> read_asciistl(const std::filesystem::path& filename) noexcept
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
        return std::nullopt;
    }
    return raw_data;
}

} // namespace details


template<types::mesh T>
[[nodiscard]] std::optional<T> import_mesh(const std::filesystem::path& filename, const filetypes file_types = filetypes::AUTODETECT) noexcept
{
    if (! exists(filename))
    {
        spdlog::error("File {} doesn't exist", filename.string());
        return std::nullopt;
    }
    spdlog::info("Reading file {}", filename.string());

    if (file_types != filetypes::STL_ASCII)
    {
        // TODO: implement autodetect for now assume ASCII STL
        spdlog::error("Not yet implemented file type {}", static_cast<int>(file_types));
        return std::nullopt;
    }

    auto raw_data{ details::read_asciistl(filename) };
    if (! raw_data.has_value())
    {
        return std::nullopt;
    }

    try
    {
        auto mesh = details::translate_asciistl<T>(raw_data.value());
        return mesh;
    }
    catch (const std::exception& e)
    {
        spdlog::error("Error while parsing file {}: {}", filename.string(), e.what());
        return std::nullopt;
    }
    return std::nullopt;
}

} // namespace nail::files

#endif // NAILCLIPPER_MESH_H
