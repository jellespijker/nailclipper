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

template<Number T>
[[nodiscard]] constexpr Mesh auto translateASCIISTL(std::string_view data)
{
    namespace rg = ranges;
    namespace rv = ranges::views;
    mesh_t<T> mesh{};
    for (auto loop : ctre::range<"loop.+?endloop">(data))
    {
        auto face = ctre::range<"[\\d\\.]+">(loop);
        mesh.emplace_back(face
                          | rv::transform(
                            [](auto s)
                            {
                                T d;
                                std::from_chars(s.begin(), s.end(), d);
                                return d;
                            })
                          | rv::chunk(3)
                          | rv::transform(
                            [](auto point) {
                                return point3d_t<T>{ static_cast<T>(*point.begin()), 3 };
                            })
                          | rg::to_vector);
    }
    // TODO: Handle exceptions thrown by from_chars
    // TODO: Handle the creation of point3d_t gracefully

    return mesh;
}

} // namespace nail::mesh

#endif // NAILCLIPPER_MESH_H
