# Copyright (c) 2022 Jelle Spijker
# NailClipper is released under the terms of the AGPLv3 or higher

find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

set(SRC_TEST tests.cpp test_io.cpp)
if (WITH_MESH)
    list(APPEND SRC_TEST test_mesh.cpp test_stl.h)
endif ()
add_executable(tests ${SRC_TEST})
target_link_libraries(tests PRIVATE project_options Catch2::Catch2 NailClipper curaengine-lite)

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