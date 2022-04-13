# Copyright (c) 2022 Jelle Spijker
# NailClipper is released under the terms of the AGPLv3 or higher

cmake_minimum_required(VERSION 3.21)
project(NailClipper CXX)

include(cmake/StandardProjectSettings.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
#set_project_warnings(project_warnings)

find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)
find_package(range-v3 REQUIRED)

set(SRC src/Clipper.cpp
        )

set(HDR
        include/NailClipper/Clipper.h
        )

add_library(NailClipper ${SRC} ${HDR})

target_link_libraries(NailClipper
        PRIVATE
        project_options
        project_warnings
        spdlog::spdlog
        fmt::fmt
        range-v3::range-v3
        )

target_include_directories(NailClipper
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        src)

option(ENABLE_TESTS "Build with unit test" ON)
if (ENABLE_TESTS)
    enable_testing()
    message("Building Tests")
    add_subdirectory(tests)
endif ()

option(ENABLE_BENCHMARKS "Build with benchmarks" ON)
if (ENABLE_BENCHMARKS)
    message("Building Benchmarks")
    add_subdirectory(curaengine-lite)
    add_subdirectory(benchmarks)
endif ()