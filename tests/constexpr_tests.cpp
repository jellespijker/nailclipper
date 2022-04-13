// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <catch2/catch.hpp>

constexpr unsigned int Factorial(unsigned int number) // NOLINT(misc-no-recursion)
{
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed with constexpr", "[factorial]")
{
    STATIC_REQUIRE(Factorial(1) == 1);
    STATIC_REQUIRE(Factorial(2) == 2);
    STATIC_REQUIRE(Factorial(3) == 6);
    STATIC_REQUIRE(Factorial(10) == 3628800);
}