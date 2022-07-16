// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_CONVERSION_H
#define NAILCLIPPER_CONVERSION_H

#include "NailClipper/Concepts.h"
#include "NailClipper/Conversion/VTU.h"
#include <range/v3/all.hpp>
#include <range/v3/distance.hpp>
#include <range/v3/view/join.hpp>
#include <spdlog/spdlog.h>

namespace nail::conversion
{

auto formatVTU(GeometricCollection auto data)
{
    spdlog::info("Converting to VTU");
    //    auto data_ = data | ranges::v3::to_vector;  // FIXME: why do I need to_vector here?
    auto doc = detail::vtkFileDoc("UnstructuredGrid");
    // TODO: Assert if GeometricCollection is indeed a collection of GeometricData
    auto points_view = data | ranges::view::join;
    auto no_of_points = ranges::distance(points_view);
    auto no_of_cells = ranges::distance(data);

    spdlog::debug("Number of points: {}", no_of_points);
    spdlog::debug("Number of cells: {}", no_of_cells);

    auto piece = detail::vtkPiece(doc, no_of_points, no_of_cells);

    auto point_data = piece.append_child("PointData"); // TODO: add specific logic to convert the data
    auto cell_data = piece.append_child("CellData"); // TODO: add specific logic to convert the data
    auto points = detail::vtkPoints(doc, points_view);

    auto cells = detail::vtkCells(doc, data, points_view);

    return doc;
};

} // namespace nail::conversion

#endif // NAILCLIPPER_CONVERSION_H
