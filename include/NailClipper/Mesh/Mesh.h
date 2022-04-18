// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_MESH_H
#define NAILCLIPPER_MESH_H

#include <filesystem>
#include <optional>
#include <string_view>

#include <spdlog/spdlog.h>

#include <ctre.hpp>

#include <range/v3/all.hpp>
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/chunk.hpp>
#include <range/v3/view/transform.hpp>

#include "NailClipper/Mesh/FileTypes.h"
#include <NailClipper/Types.h>

namespace nail::mesh
{

template<Number T>
[[nodiscard]] constexpr Number auto toNumber(std::string_view view) noexcept
{
    T n;
    std::from_chars(view.begin(), view.end(), n);
    return n;
}

template<Number T>
[[nodiscard]] constexpr Mesh auto translateASCIISTL(std::string_view data)
{
    auto vertexes = ctre::multiline_range<R"(\s+vertex\s([\-\d]*\.?\d*)\s([\-\d]*\.?\d*)\s([\-\d]*\.?\d*))">(data);
    return vertexes
         | ranges::views::transform(
             [](auto point) {
                 return point3d_t<T>{ toNumber<T>(get<1>(point)), toNumber<T>(get<2>(point)), toNumber<T>(get<3>(point)) };
             })
         | ranges::views::chunk(3) | ranges::to<mesh_t<T>>;
}

[[nodiscard]] std::string readASCIISTL(const std::filesystem::path& filename) noexcept;

template<Number T>
[[nodiscard]] Mesh auto importMesh(const std::filesystem::path& filename, const FileTypes& file_types = FileTypes::AUTODETECT)
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
    return translateASCIISTL<T>(data_view);
};

} // namespace nail::mesh

#endif // NAILCLIPPER_MESH_H
