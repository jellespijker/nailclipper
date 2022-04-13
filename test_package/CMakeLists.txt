# Copyright (c) 2022 Jelle Spijker
# NailClipper is released under the terms of the AGPLv3 or higher

cmake_minimum_required(VERSION 3.21)
project(NailClipperTestPackage CXX)

find_package(NailClipper REQUIRED)

add_executable(test main.cpp)
target_link_libraries(test PRIVATE NailClipper::NailClipper)