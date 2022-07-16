// Copyright (c) 2022 Jelle Spijker
// NailClipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_SCALE_H
#define NAILCLIPPER_SCALE_H

#include "NailClipper/Concepts.h"
#include "NailClipper/Views/Transform.h"
#include <range/v3/functional/arithmetic.hpp>

namespace nail::views
{
inline constexpr auto scale(Point auto& vec)
{
    return ranges::make_view_closure(
      [&vec](auto&& rng)
      { return detail::transform_fn(std::forward<decltype(rng)>(rng), vec, std::forward<ranges::multiplies>(ranges::multiplies{})); });
}
} // namespace nail::views

#endif // NAILCLIPPER_SCALE_H
