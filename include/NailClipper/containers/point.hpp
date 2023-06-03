// Copyright (c) 2023. Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_CONTAINERS_POINT_HPP
#define NAILCLIPPER_CONTAINERS_POINT_HPP

#include <tuple>

#include "NailClipper/types/generic.hpp"

namespace nail
{

template<types::numerical Tp, types::numerical... Tps>
struct point : public std::tuple<Tp, Tps...>
{
    using std::tuple<Tp, Tps...>::tuple;
    constexpr inline static std::size_t tuple_size{ sizeof...(Tps) + 1 };

    constexpr point(Tp&& x, Tps&&... coords) noexcept : std::tuple<Tp, Tps...>(std::forward<Tp>(x), std::forward<Tps>(coords)...)
    {
        static_assert(sizeof...(Tps) == 1 || sizeof...(Tps) == 2, "Point can only be 2 or 3 dimensional");
    }
};

// CTAD
template<types::numerical Tx, types::numerical Ty>
    requires std::same_as<Tx, Ty>
point(Tx, Ty) -> point<Tx, Ty>;

template<types::numerical Tx, types::numerical Ty, types::numerical Tz>
    requires std::same_as<Tx, Ty> && std::same_as<Ty, Tz>
point(Tx, Ty, Tz) -> point<Tx, Ty, Tz>;

} // namespace nail


namespace std
{
template<typename Tp, typename... Tps>
struct tuple_size<nail::point<Tp, Tps...>> : std::integral_constant<std::size_t, nail::point<Tp, Tps...>::tuple_size>
{
};
} // namespace std

#endif // NAILCLIPPER_CONTAINERS_POINT_HPP
