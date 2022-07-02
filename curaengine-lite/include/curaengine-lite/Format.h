// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_FORMAT_H
#define NAILCLIPPER_FORMAT_H

#include <fmt/format.h>
#include <fmt/ranges.h>

#include "curaengine-lite/IntPoint.h"
#include "curaengine-lite/polygon.h"

template<>
struct fmt::formatter<cura::Point>
{
    char presentation = 'i';

    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin())
    {
        auto it = ctx.begin(), end = ctx.end();
        if (it != end && (*it == 'i' || *it == 'a'))
            presentation = *it++;

        if (it != end && *it != '}')
            throw format_error("invalid format");

        return it;
    }
    template<typename FormatContext>
    auto format(cura::Point p, FormatContext& ctx) -> decltype(ctx.out())
    {
        return presentation == 'i' ? format_to(ctx.out(), "{}, {}", p.X, p.Y) : format_to(ctx.out(), "[{}, {}]", p.X, p.Y);
    }
};

template<>
struct fmt::formatter<cura::Polygons>
{
    char presentation = 'f';

    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin())
    {
        auto it = ctx.begin(), end = ctx.end();
        if (it != end && (*it == 'f' || *it == 'e'))
            presentation = *it++;

        if (it != end && *it != '}')
            throw format_error("invalid format");

        return it;
    }
    template<typename FormatContext>
    auto format(const cura::Polygons& p, FormatContext& ctx) -> decltype(ctx.out())
    {
        return presentation == 'f' ? format_to(ctx.out(), "{}", fmt::join(p, ", ")) : format_to(ctx.out(), "{:.1e}", p);
    }
};

#endif // NAILCLIPPER_FORMAT_H
