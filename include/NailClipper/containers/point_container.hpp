// Copyright (c) 2023. UltiMaker & Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher

#ifndef GEOMETRY_POINT_CONTAINER_H
#define GEOMETRY_POINT_CONTAINER_H

#include <initializer_list>
#include <memory>
#include <vector>

#include <range/v3/range/operations.hpp>
#include <range/v3/view/drop.hpp>
#include <range/v3/view/transform.hpp>

#include "NailClipper/containers/winding.hpp"
#include "NailClipper/containers/point.hpp"
#include "NailClipper/types/geometry.h"

namespace nail
{
/*! The base clase of all point based container types
 *
 * @tparam P
 * @tparam IsClosed
 * @tparam Direction
 * @tparam Container
 */
template<utils::point P, bool IsClosed, winding Direction, bool IsFilled, template<class> class Container>
requires utils::point<typename Container<P>::value_type> struct point_container : public Container<P>
{
    inline static constexpr bool is_filled = IsFilled;
    inline static constexpr bool is_closed = IsClosed;
    inline static constexpr winding direction = Direction;
};

template<utils::point P = Point, template<class> class Container = std::vector>
struct open_path : public point_container<P, false, winding::NA, false, Container>
{
    constexpr open_path() noexcept = default;
    constexpr open_path(std::initializer_list<P> points) noexcept : point_container<P, false, winding::NA, false, Container>(points)
    {
    }

    constexpr open_path(const std::vector<P>& points) noexcept : point_container<P, false, winding::NA, false, Container>(points)
    {
    }
};

template<utils::point P = Point, template<class> class Container = std::vector>
open_path(std::initializer_list<P>) -> open_path<P, Container>;
template<utils::point P = Point>
open_path(const std::vector<P>&) -> open_path<P, std::vector>;

template<utils::point P, winding Direction, template<class> class Container>
struct closed_path : public point_container<P, true, Direction, false, Container>
{
    constexpr closed_path() noexcept = default;
    constexpr closed_path(std::initializer_list<P> points) noexcept : point_container<P, true, Direction, false, Container>(points)
    {
    }
};

template<utils::point P = Point, template<class> class Container = std::vector>
closed_path(std::initializer_list<P>) -> closed_path<P, winding::NA, Container>;

template<utils::point P, winding Direction, template<class> class Container>
struct filled_path : public point_container<P, true, Direction, true, Container>
{
    constexpr filled_path() noexcept = default;
    constexpr filled_path(std::initializer_list<P> points) noexcept : point_container<P, true, Direction, true, Container>(points)
    {
    }
};

template<utils::point P = Point, template<class> class Container = std::vector>
filled_path(std::initializer_list<P>) -> filled_path<P, winding::NA, Container>;

template<utils::point P = Point, template<class> class Container = std::vector>
struct filled_path_outer : public point_container<P, true, winding::CW, true, Container>
{
    constexpr filled_path_outer() noexcept = default;
    constexpr filled_path_outer(std::initializer_list<P> points) noexcept : point_container<P, true, winding::CW, true, Container>(points)
    {
    }
};

template<utils::point P = Point, template<class> class Container = std::vector>
filled_path_outer(std::initializer_list<P>) -> filled_path_outer<P, Container>;

template<utils::point P = Point, template<class> class Container = std::vector>
struct filled_path_inner : public point_container<P, true, winding::CCW, true, Container>
{
    constexpr filled_path_inner() noexcept = default;
    constexpr filled_path_inner(std::initializer_list<P> points) noexcept : point_container<P, true, winding::CCW, true, Container>(points)
    {
    }
};

template<utils::point P = Point, template<class> class Container = std::vector>
filled_path_inner(std::initializer_list<P>) -> filled_path_inner<P, Container>;
filled_path_inner(std::vector<Point>) -> filled_path_inner<Point, std::vector>; // TODO: Remove once we finally get rid of Polygon

template<utils::point P, template<class> class Container>
struct ranged_paths : public Container<point_container<P, false, winding::NA, false, Container>>
{
    constexpr ranged_paths() noexcept = default;
    constexpr ranged_paths(std::initializer_list<point_container<P, false, winding::NA, false, Container>> paths) noexcept
    {
        for (const auto& path : paths)
        {
            this->emplace_back(path);
        }
    }
};

template<utils::point P = Point, template<class> class Container = std::vector>
ranged_paths(std::initializer_list<point_container<P, false, winding::NA, false, Container>>) -> ranged_paths<Point, Container>;

template<utils::point P, template<class> class Container>
struct polygon : public ranged_paths<P, Container>
{
    constexpr polygon() noexcept = default;
    constexpr polygon(std::initializer_list<point_container<P, false, winding::NA, false, Container>> paths) noexcept : ranged_paths<P, Container>(paths)
    {
    }

    constexpr auto outer() const
    {
        return static_cast<filled_path_outer<P, Container>>(this->front());
    }

    constexpr auto inners() const
    {
        return this | ranges::views::drop(1) | ranges::views::transform([](const auto& path) { return static_cast<filled_path_inner<P, Container>>(path); });
    }
};

template<utils::point P, template<class> class Container>
struct polygons : public Container<polygon<P, Container>>
{
    constexpr polygons() noexcept = default;
    constexpr polygons(std::initializer_list<polygon<P, Container>> polygons) noexcept : Container<polygon<P, Container>>(polygons)
    {
    }
};
} // namespace nail

#endif // GEOMETRY_POINT_CONTAINER_H
