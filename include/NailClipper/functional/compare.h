// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher


#ifndef NAILCLIPPER_COMPARE_H
#define NAILCLIPPER_COMPARE_H

#include "NailClipper/concepts.h"

namespace nail
{

struct higher
{
    template<Point T, Point U>
    constexpr auto operator()(T&& t, U&& u) const
    {
        return std::forward<T>(t) > std::forward<U>(u);
    }
    using is_transparent = void;
};

struct lower
{
    template<Point T, Point U>
    constexpr auto operator()(T&& t, U&& u) const
    {
        return std::forward<T>(t) < std::forward<U>(u);
    }
    using is_transparent = void;
};

struct between
{
    template<Point T, Point U, Point V>
    constexpr auto operator()(T&& t, U&& u, V&& v) const
    {
        return std::forward<T>(t) > std::forward<U>(u) && std::forward<T>(t) < std::forward<V>(v);
    }
    using is_transparent = void;
};

} // namespace nail

#endif // NAILCLIPPER_COMPARE_H
