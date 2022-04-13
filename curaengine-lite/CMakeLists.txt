# Copyright (c) 2022 Ultimaker B.V.
# CuraEngine is released under the terms of the AGPLv3 or higher.

find_package(clipper REQUIRED)
find_package(spdlog REQUIRED)

set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/LinearAlg2D.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ListPolyIt.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Point3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/polygon.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/PolyLineStitcher.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Slicer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/SquareGrid.cpp)

set(HDR ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/Angle.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/Coord_t.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/ExtrusionJunction.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/ExtrusionLine.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/IntPoint.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/LinearAlg2D.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/ListPolyIt.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/math.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/Point3.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/polygon.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/PolygonsPointIndex.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/PolyLineStitcher.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/Ratio.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/Slicer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/SparseGrid.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/SparsePointGrid.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/SquareGrid.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/curaengine-lite/SymmetricPair.h
        )

add_library(curaengine-lite SHARED ${SRC} ${HDR})
target_link_libraries(curaengine-lite PRIVATE project_warnings project_options PUBLIC clipper::clipper spdlog::spdlog)
target_include_directories(curaengine-lite
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)
