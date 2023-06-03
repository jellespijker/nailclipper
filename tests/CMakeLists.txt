# Copyright (c) 2022 Jelle Spijker
# NailClipper is released under the terms of the AGPLv3 or higher

find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

set(SRC_TEST main.cpp test_container.cpp test_views.cpp test_mesh.cpp test_stl.h)

add_executable(tests ${SRC_TEST})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain nailclipper)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(tests
        TEST_PREFIX
        "unittests."
        OUTPUT_DIR
        .
        OUTPUT_PREFIX
        "unittests."
        OUTPUT_SUFFIX
        .xml)