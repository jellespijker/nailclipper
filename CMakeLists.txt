# Copyright (c) 2022 Jelle Spijker
# NailClipper is released under the terms of the AGPLv3 or higher

cmake_minimum_required(VERSION 3.23)
project(nailclipper CXX)

add_library(project_options INTERFACE)
find_package(standardprojectsettings REQUIRED)
enable_sanitizers(project_options)
target_compile_features(project_options INTERFACE cxx_std_20)

add_library(project_warnings INTERFACE)
set_project_warnings(project_warnings)

find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)
find_package(range-v3 REQUIRED)
find_package(ctre REQUIRED)

set(HDR
        include/NailClipper/containers/mesh.hpp
        include/NailClipper/containers/paths.hpp
        include/NailClipper/containers/point.hpp
        include/NailClipper/containers/winding.hpp
        include/NailClipper/files/filetypes.hpp
        include/NailClipper/files/stl.hpp
        include/NailClipper/types/char_range_literal.hpp
        include/NailClipper/types/generic.hpp
        include/NailClipper/types/geometry.hpp
        include/NailClipper/types/get.hpp
        include/NailClipper/types/type_traits.hpp
        include/NailClipper/views/path.hpp
        include/NailClipper/views/segments.hpp
)


add_library(nailclipper INTERFACE ${HDR})
enable_sanitizers(nailclipper)

target_link_libraries(nailclipper
        INTERFACE
        project_options
        project_warnings
        range-v3::range-v3
        spdlog::spdlog
        ctre::ctre
        fmt::fmt
)

target_include_directories(nailclipper
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

option(ENABLE_TESTS "Build with unit test" ON)
option(ENABLE_BENCHMARKS "Build with benchmarks" ON)

if (ENABLE_TESTS)
    message(STATUS "NailClipper: Compiling with Tests")
    enable_testing()
    add_subdirectory(tests)
endif ()

if (ENABLE_BENCHMARKS)
    message(STATUS "NailClipper: Compiling with Benchmarks")
    add_subdirectory(benchmarks)
endif ()

option(ENABLE_PLAYGROUND "Build with playground" ON)
if (ENABLE_PLAYGROUND)
    message(STATUS "NailClipper: Compiling with Playground")
    add_subdirectory(playground)
endif ()
