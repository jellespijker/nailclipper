// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_POINT_H
#define NAILCLIPPER_POINT_H

#include "NailClipper/Concepts.h"
#include <array>

namespace nail::types
{

template<Number T, std::size_t N>
struct point
{
    using value_type = T;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using reference = value_type&;
    using cons_reference = const value_type&;
    using iterator = value_type*;
    using const_iterator = const value_type*;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // Support for zero-sized arrays mandatory.
    using T_Type = _GLIBCXX_STD_C::__array_traits<T, N>;
    typename T_Type::_Type M_elems;


    _GLIBCXX17_CONSTEXPR iterator begin() noexcept
    {
        return iterator(data());
    }

    _GLIBCXX17_CONSTEXPR pointer data() noexcept
    {
        return T_Type::_S_ptr(M_elems);
    }

    _GLIBCXX17_CONSTEXPR const_pointer data() const noexcept
    {
        return T_Type::_S_ptr(M_elems);
    }
};
}; // namespace nail::types

#endif // NAILCLIPPER_POINT_H
