// Copyright (c) 2023. UltiMaker & Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher

#ifndef UTILS_TYPES_TYPE_TRAITS_H
#define UTILS_TYPES_TYPE_TRAITS_H

#include "NailClipper/types/generic.hpp"

namespace nail::types
{

template<class T>
class is_filled
{
    inline static constexpr bool value_() noexcept
    {
        if constexpr (fillable<T>)
        {
            return T::is_filled == true;
        }
        else
        {
            return false;
        }
    }

public:
    inline static constexpr bool value = value_();
};

template<class T>
inline constexpr bool is_filled_v = is_filled<T>::value;

template<class T>
class is_closed
{
    inline static constexpr bool value_() noexcept
    {
        if constexpr (closable<T>)
        {
            return T::is_closed == true;
        }
        else
        {
            return false;
        }
    }

public:
    inline static constexpr bool value = value_();
};

template<class T>
inline constexpr bool is_closed_v = is_closed<T>::value;

template<class T>
inline constexpr bool is_open_v = ! is_closed_v<T>;

template<class T>
class direction
{
    inline static constexpr winding value_() noexcept
    {
        if constexpr (directional<T>)
        {
            return T::direction;
        }
        else
        {
            return winding::NA;
        }
    }

public:
    inline static constexpr winding value = value_();
};

template<class T>
inline constexpr winding direction_v = direction<T>::value;

template<class T>
inline constexpr bool is_cw_v = direction_v<T> == winding::CW;

template<class T>
inline constexpr bool is_ccw_v = direction_v<T> == winding::CCW;

} // namespace nail::types

#endif // UTILS_TYPES_TYPE_TRAITS_H
