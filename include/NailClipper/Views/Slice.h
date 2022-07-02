// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_SLICE_H
#define NAILCLIPPER_SLICE_H

#include <range/v3/view_interface.hpp>
#include <ranges>

#include "NailClipper/Concepts.h"

namespace nail::views
{
template<std::ranges::view V, Number Delta>
    requires std::ranges::bidirectional_range<V>
class slice_view : public ranges::view_interface<slice_view<V, Delta>>
{
    V m_base;
    Delta m_delta;

  public:
    slice_view() = default;

    slice_view(V base, Delta delta) : m_base(std::move(base)), m_delta(std::move(delta)){};

    auto begin()
    {
        return std::ranges::begin(m_base);
    };

    auto end()
    {
        return std::ranges::end(m_base);
    };
};

using std::views::__adaptor::_RangeAdaptor;

struct slice_view_fn : _RangeAdaptor<slice_view_fn>
{
    template<std::ranges::viewable_range R, Number Delta>
    constexpr auto operator()(R&& r, Delta delta) const -> slice_view<std::views::all_t<R>, Delta>
    {
        return slice_view<std::views::all_t<R>, Delta>(std::views::all(std::forward<R>(r)), std::move(delta));
    }

    using _RangeAdaptor<slice_view_fn>::operator();

    static constexpr int _S_arity = 2;
};

inline constexpr auto slice = slice_view_fn{};

} // namespace nail::views
#endif // NAILCLIPPER_SLICE_H
