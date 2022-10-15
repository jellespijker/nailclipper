// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_SCALE_H
#define NAILCLIPPER_SCALE_H

#include "NailClipper/views/elem_wise_op.h"

#include <range/v3/functional/arithmetic.hpp>

namespace nail::views
{
[[nodiscard, maybe_unused]] constexpr auto scale(Point auto vec)
{
    return ranges::make_view_closure(elem_wise_op(vec, ranges::multiplies{}));
}

} // namespace nail::views

#endif // NAILCLIPPER_SCALE_H
