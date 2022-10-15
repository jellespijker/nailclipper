// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_VIEWS_ELEM_WISE_OP_H
#define NAILCLIPPER_VIEWS_ELEM_WISE_OP_H

#include "NailClipper/concepts.h"

#include <range/v3/view/transform.hpp>
#include <range/v3/view/zip.hpp>
#include <range/v3/view_facade.hpp>

namespace nail::views
{
namespace detail
{
template<Point Vec, class Proj, class Begin, class End>
class elem_wise_op_view : public ranges::view_facade<elem_wise_op_view<Vec, Proj, Begin, End>>
{
    friend ranges::range_access;

    Vec vec_;
    Proj proj_;
    Begin it_;
    End end_;

    [[maybe_unused]] constexpr void next()
    {
        ++it_;
    }

    [[nodiscard, maybe_unused]] constexpr bool equal(ranges::default_sentinel_t /*unused*/) const
    {
        return it_ == end_;
    }

    [[nodiscard, maybe_unused]] constexpr auto read() const
    {
        return ranges::views::zip(*it_, vec_) | ranges::views::transform([&](const auto& pair) { return std::invoke(proj_, pair.first, pair.second); });
    }

public:
    constexpr elem_wise_op_view() noexcept = default;

    constexpr elem_wise_op_view(Vec vec, Proj proj, Begin begin, End end) noexcept : vec_{ vec }, proj_{ proj }, it_{ begin }, end_{ end } {};
};

template<Point Vec, class Proj>
class elem_wise_op_fn
{
    Vec vec_;
    Proj proj_;

public:
    constexpr elem_wise_op_fn() noexcept = default;
    constexpr elem_wise_op_fn(Vec vec, Proj proj) noexcept : vec_{ vec }, proj_{ proj } {};

    [[nodiscard]] constexpr auto operator()(GeometricData auto rng) noexcept
    {
        return elem_wise_op_view(vec_, proj_, ranges::begin(rng), ranges::end(rng));
    }
};

} // namespace detail

[[nodiscard, maybe_unused]] constexpr auto elem_wise_op(const Point auto& vec, const auto& proj)
{
    return ranges::make_view_closure(detail::elem_wise_op_fn{ vec, proj });
}

} // namespace nail::views

#endif // NAILCLIPPER_VIEWS_ELEM_WISE_OP_H
