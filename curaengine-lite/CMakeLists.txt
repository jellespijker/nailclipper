# Copyright (c) 2022 Jelle Spijker
# NailClipper is released under the terms of the AGPLv3 or higher

find_package(clipper REQUIRED)
find_package(spdlog REQUIRED)

add_library(curaengine-lite polygon.cpp Point3.cpp LinearAlg2D.cpp Coord_t.h Angle.h Ratio.h ListPolyIt.cpp PolyLineStitcher.cpp ExtrusionLine.h ExtrusionJunction.h SparsePointGrid.h PolygonsPointIndex.h SparseGrid.h SquareGrid.cpp SymmetricPair.h IntPoint.h Slicer.cpp)
target_link_libraries(curaengine-lite PRIVATE project_warnings project_options clipper::clipper)
target_include_directories(curaengine-lite PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})