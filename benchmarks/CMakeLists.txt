# Copyright (c) 2022 Jelle Spijker
# NailClipper is released under the terms of the AGPLv3 or higher

find_package(benchmark REQUIRED)

add_executable(benchmarks main.cpp)
target_link_libraries(benchmarks PRIVATE project_warnings project_options benchmark::benchmark curaengine-lite)
target_include_directories(benchmarks PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})