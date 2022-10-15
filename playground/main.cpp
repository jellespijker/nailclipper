// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#include <array>
#include <concepts>
#include <iostream>
#include <range/v3/all.hpp>

#include "NailClipper/views/scale.h"
#include "NailClipper/views/translate.h"

int main()
{
    std::array<double, 2> vec{ 20.0, 1.0 };
    std::array<double, 2> scaling_vec{ 2.0, 2.0 };
    std::vector<std::array<double, 2>> poly{ { 100., 2. }, { 3.0, 4.0 }, { 6.0, 9.0 }, { 5.5, 1.25 } };

    auto translated = poly | nail::views::translate(vec) | nail::views::scale(scaling_vec);

    ranges::for_each(translated, [](auto point) { std::cout << point << std::endl; });

    return 0;
}