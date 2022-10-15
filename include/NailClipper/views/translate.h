// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_TRANSLATE_H
#define NAILCLIPPER_TRANSLATE_H

#include "NailClipper/views/elem_wise_op.h"

#include <range/v3/functional/arithmetic.hpp>

namespace nail::views
{
[[nodiscard, maybe_unused]] constexpr auto translate(Point auto vec)
{
    return ranges::make_view_closure(elem_wise_op(vec, ranges::plus{}));
}

} // namespace nail::views

#endif // NAILCLIPPER_TRANSLATE_H