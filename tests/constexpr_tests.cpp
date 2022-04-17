// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <catch2/catch.hpp>

#include <string_view>

#include "NailClipper/Concepts.h"
#include "NailClipper/Types.h"

using namespace std::literals;

TEST_CASE("Split a string view", "[split_view]")
{
    constexpr auto test = "Test 1\n Test2\n Test3"sv;
    STATIC_REQUIRE(true);
}