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

set(SRC src/Clipper.cpp)

set(HDR
        include/NailClipper/Clipper.h
        include/NailClipper/Concepts.h
        include/NailClipper/Types.h
        )

option(WITH_MESH "Build with mesh support" ON)
if (WITH_MESH)
    message(STATUS "NailClipper: Compiling with Mesh Support")
    list(APPEND SRC
            src/Mesh.cpp
            )
    list(APPEND HDR
            include/NailClipper/Mesh/Mesh.h
            include/NailClipper/Mesh/FileTypes.h)
    find_package(ctre REQUIRED)
    target_compile_definitions(project_options INTERFACE WITH_MESH)
endif ()

add_library(NailClipper ${SRC} ${HDR})

target_link_libraries(NailClipper
        PUBLIC
        project_options
        range-v3::range-v3
        spdlog::spdlog
        PRIVATE
        project_warnings
        fmt::fmt
        )
if (${WITH_MESH})
    target_link_libraries(NailClipper PUBLIC ctre::ctre)
endif ()

target_include_directories(NailClipper
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        src)

option(ENABLE_TESTS "Build with unit test" ON)
option(ENABLE_BENCHMARKS "Build with benchmarks" ON)
if(ENABLE_TEST OR ENABLE_BENCHMARKS)
    add_subdirectory(curaengine-lite)
endif()

if (ENABLE_TESTS)
    message(STATUS "NailClipper: Compiling with Tests")
    enable_testing()
    add_subdirectory(tests)
endif ()


if (ENABLE_BENCHMARKS)
    message(STATUS "NailClipper: Compiling with Benchmarks")
    add_subdirectory(benchmarks)
endif ()