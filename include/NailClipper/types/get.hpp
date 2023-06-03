// Copyright (c) 2023. UltiMaker & Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher

#ifndef UTILS_TYPES_GET_H
#define UTILS_TYPES_GET_H

#include "NailClipper/types/char_range_literal.hpp"
#include "NailClipper/types/geometry.hpp"

namespace std
{
template<size_t N>
constexpr auto& get(nail::types::point2d_named auto& point) noexcept
{
    static_assert(N < 2, "Index out of bounds");
    if constexpr (N == 0)
    {
        return point.X;
    }
    return point.Y;
}

template<size_t N>
constexpr auto& get(nail::types::point2d_named_lowercase auto& point) noexcept
{
    static_assert(N < 2, "Index out of bounds");
    if constexpr (N == 0)
    {
        return point.x;
    }
    return point.y;
}

template<nail::types::char_range_literal C>
constexpr auto& get(nail::types::point2d auto& point) noexcept
{
    constexpr std::string_view idx = C.value;
    static_assert(idx.starts_with("X") || idx.starts_with("x") || idx.starts_with("Y") || idx.starts_with("y"), "Index out of bounds");
    if constexpr (idx.starts_with("X") || idx.starts_with("x"))
    {
        return std::get<0>(point);
    }
    return std::get<1>(point);
}

template<size_t N>
constexpr auto& get(nail::types::point3d_named auto& point) noexcept
{
    static_assert(N < 3, "Index out of bounds");
    if constexpr (N == 0)
    {
        return point.X;
    }
    else if constexpr (N == 1)
    {
        return point.Y;
    }
    return point.Z;
}

template<size_t N>
constexpr auto& get(nail::types::point3d_named_lowercase auto& point) noexcept
{
    static_assert(N < 3, "Index out of bounds");
    if constexpr (N == 0)
    {
        return point.x;
    }
    else if constexpr (N == 1)
    {
        return point.y;
    }
    return point.z;
}

template<nail::types::char_range_literal C>
constexpr auto& get(nail::types::point3d auto& point) noexcept
{
    constexpr std::string_view idx = C.value;
    static_assert(idx.starts_with("X") || idx.starts_with("x") || idx.starts_with("Y") || idx.starts_with("y") || idx.starts_with("Z") || idx.starts_with("z"), "Index out of bounds");
    if constexpr (idx.starts_with("X") || idx.starts_with("x"))
    {
        return std::get<0>(point);
    }
    if constexpr (idx.starts_with("Y") || idx.starts_with("y"))
    {
        return std::get<1>(point);
    }
    return std::get<2>(point);
}

} // namespace std


#endif // UTILS_TYPES_GET_H