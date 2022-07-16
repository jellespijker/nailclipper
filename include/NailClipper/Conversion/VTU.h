// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_VTU_H
#define NAILCLIPPER_VTU_H

#include "NailClipper/Concepts.h"
#include <filesystem>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <pugixml.hpp>
#include <range/v3/distance.hpp>
#include <range/v3/view/generate.hpp>
#include <range/v3/view/iota.hpp>
#include <range/v3/view/join.hpp>
#include <range/v3/view/partial_sum.hpp>
#include <range/v3/view/take.hpp>
#include <range/v3/view/transform.hpp>
#include <spdlog/spdlog.h>
#include <type_traits>

namespace nail::conversion::detail
{

auto vtkFileDoc(const auto& extension)
{
    spdlog::info("Creating VTK header for {}", extension);
    pugi::xml_document doc;
    auto root = doc.append_child("VTKFile");
    root.append_attribute("type").set_value("UnstructuredGrid");
    root.append_attribute("version").set_value("1.0");
    root.append_attribute("byte_order").set_value("LittleEndian");
    root.append_attribute("header_type") = "UInt64";

    root.append_child(extension);
    return doc;
}

auto vtkPiece(pugi::xml_document& doc, const auto& no_of_points, const auto& no_of_cells)
{
    spdlog::info("Creating VTK piece");
    auto root = doc.child("VTKFile").first_child();
    auto piece = root.append_child("Piece");
    piece.append_attribute("NumberOfPoints") = no_of_points;
    piece.append_attribute("NumberOfCells") = no_of_cells;
    return piece;
}

auto vtkPoints(pugi::xml_document& doc, const auto& points_view)
{
    spdlog::info("Creating VTK points");
    auto root = doc.child("VTKFile").first_child().first_child();
    auto points = root.append_child("Points");
    auto points_data = points.append_child("DataArray");
    points_data.append_attribute("type") = "Float64"; // TODO : determine from underlying type in GeometricCollection
    points_data.append_attribute("Name") = "Points";
    points_data.append_attribute("NumberOfComponents") = "3";
    auto coordinate_view = points_view | ranges::view::join; // TODO: pad z = 0 if 2D
    auto coordinate_data = fmt::format("{}", fmt::join(coordinate_view, " "));
    points_data.append_child(pugi::node_pcdata).set_value(coordinate_data.c_str());
    return points;
}

auto vtkCells(pugi::xml_document& doc, const GeometricCollection auto& data, const auto& points_view)
{
    spdlog::info("Creating VTK cells");
    auto root = doc.child("VTKFile").first_child().first_child();
    auto cells = root.append_child("Cells");
    auto connectivity = cells.append_child("DataArray");
    connectivity.append_attribute("type") = "Int64"; // TODO : determine from underlying type in GeometricCollection
    connectivity.append_attribute("Name") = "connectivity";
    connectivity.append_attribute("format") = "ascii";
    auto connecitvity_view = ranges::view::iota(0, ranges::distance(points_view));
    auto connectivity_data = fmt::format("{}", fmt::join(connecitvity_view, " "));
    connectivity.append_child(pugi::node_pcdata).set_value(connectivity_data.c_str());

    auto offsets = cells.append_child("DataArray");
    offsets.append_attribute("type") = "Int64"; // TODO : determine from underlying type in GeometricCollection
    offsets.append_attribute("Name") = "offsets";
    offsets.append_attribute("format") = "ascii";
    auto offsets_view =
      data | ranges::views::transform([](auto& shape) { return ranges::distance(shape); }) | ranges::view::partial_sum(std::plus{});
    auto offsets_data = fmt::format("{}", fmt::join(offsets_view, " "));
    offsets.append_child(pugi::node_pcdata).set_value(offsets_data.c_str());

    auto types = cells.append_child("DataArray");
    types.append_attribute("type") = "UInt8";
    types.append_attribute("Name") = "types";
    types.append_attribute("format") = "ascii";
    auto types_view = ranges::view::generate([]() { return 7; })
                    | ranges::view::take(ranges::distance(data)); // TODO: determine type for now assume polygon
    auto types_data = fmt::format("{}", fmt::join(types_view, " "));
    types.append_child(pugi::node_pcdata).set_value(types_data.c_str());
    return cells;
}

} // namespace nail::conversion::detail
#endif // NAILCLIPPER_VTU_H
