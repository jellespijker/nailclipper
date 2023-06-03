// Copyright (c) 2023. UltiMaker & Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher

#ifndef UTILS_VIEWS_SEGMENTS_H
#define UTILS_VIEWS_SEGMENTS_H

#include <range/v3/view/concat.hpp>
#include <range/v3/view/single.hpp>
#include <range/v3/view/sliding.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/reverse.hpp>

#include "NailClipper/types/geometry.h"

namespace nail::views
{
namespace details
{
struct segment_view_fn
{
    template<ranges::viewable_range Rng>
    requires (utils::closed_path<std::remove_cvref_t<Rng>> && utils::clockwise_path<std::remove_cvref_t<Rng>>) ||
             utils::clipper_path<std::remove_cvref_t<Rng>>
    constexpr auto operator()(Rng&& rng) const
    {
        return ranges::views::concat(rng, ranges::views::single(rng.front())) | ranges::views::sliding(2) | ranges::views::transform([](auto&& t) { return ranges::make_common_pair(t[0], t[1]); });
    }

    template<ranges::viewable_range Rng>
    requires utils::closed_path<std::remove_cvref_t<Rng>> && utils::counter_clockwise_path<std::remove_cvref_t<Rng>>
    constexpr auto operator()(Rng&& rng) const
    {
        return ranges::views::concat(rng, ranges::views::single(rng.front())) | ranges::views::reverse | ranges::views::sliding(2) | ranges::views::transform([](auto&& t) { return ranges::make_common_pair(t[0], t[1]); });
    }

    template<ranges::viewable_range Rng>
    requires utils::open_path<std::remove_cvref_t<Rng>>
    constexpr auto operator()(Rng&& rng) const
    {
        return ranges::views::sliding(rng, 2) | ranges::views::transform([](auto&& t) { return ranges::make_common_pair(t[0], t[1]); });
    }

    template<ranges::viewable_range Rng>
    requires utils::ranged_path<std::remove_cvref_t<Rng>>
    constexpr auto operator()(Rng&& rng) const
    {
        return rng | ranges::views::transform([this](auto&& sub_rng) { return operator()(std::forward<decltype(sub_rng)>(sub_rng)); }) | ranges::views::all;
    }
};

template<ranges::viewable_range Rng>
constexpr auto operator|(Rng&& rng, const segment_view_fn& adaptor)
{
    return adaptor(std::forward<Rng>(rng));
}
} // namespace details

RANGES_INLINE_VARIABLE(details::segment_view_fn, segments);

} // namespace nail::views

#endif // UTILS_VIEWS_SEGMENTS_H
