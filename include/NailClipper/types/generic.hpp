// Copyright (c) 2023. UltiMaker & Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher

#ifndef CURAENGINE_GENERIC_H
#define CURAENGINE_GENERIC_H

#include <concepts>
#include <functional>

#include "NailClipper/containers/winding.hpp"

namespace nail::types
{
template<typename T>
concept hashable = requires(T value) {
    {
        std::hash<T>{}(value)
    } -> std::convertible_to<std::size_t>;
};

template<class T>
concept closable = requires(T t) {
    {
        T::is_closed
    } -> std::convertible_to<bool>;
};

template<class T>
concept fillable = requires(T t) {
    {
        T::is_filled
    } -> std::convertible_to<bool>;
};

template<class T>
concept directional = requires(T t) {
    {
        T::direction
    } -> std::convertible_to<winding>;
};

template<class T>
concept numerical = std::integral<std::remove_cvref_t<T>> || std::floating_point<std::remove_cvref_t<T>>; // TODO: expand with math operations

} // namespace nail::types

#endif // CURAENGINE_GENERIC_H
