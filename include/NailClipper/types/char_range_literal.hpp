// Copyright (c) 2023. UltiMaker & Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher

#ifndef UTILS_TYPES_CHAR_RANGE_LITERAL_H
#define UTILS_TYPES_CHAR_RANGE_LITERAL_H

#include <algorithm>


namespace nail::types
{
template<size_t N>
struct char_range_literal
{
    constexpr char_range_literal(const char (&str)[N])
    {
        std::copy_n(str, N, value);
    }

    char value[N];
};

} // namespace nail::types

#endif // UTILS_TYPES_CHAR_RANGE_LITERAL_H
