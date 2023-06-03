// Copyright (c) 2022-2023. Jelle Spijker
// NailCLipper is released under the terms of the AGPLv3 or higher

#ifndef NAILCLIPPER_TEST_STL_H
#define NAILCLIPPER_TEST_STL_H

#include <string_view>

using sv = std::string_view;
static constexpr auto stl = sv(
  "solid OpenSCAD_Model"
  "  facet normal 0.994522 0.104527 0 "
  "    outer loop "
  "      vertex 90 0 5 "
  "      vertex 88.0333 18.7121 0"
  "      vertex 88.0333 18.7121 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.994522 0.104527 0"
  "    outer loop"
  "      vertex 88.0333 18.7121 0"
  "      vertex 90 0 5"
  "      vertex 90 0 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.951056 0.309018 0"
  "    outer loop"
  "      vertex 88.0333 18.7121 5"
  "      vertex 82.2191 36.6063 0"
  "      vertex 82.2191 36.6063 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.951056 0.309018 0"
  "    outer loop"
  "      vertex 82.2191 36.6063 0"
  "      vertex 88.0333 18.7121 5"
  "      vertex 88.0333 18.7121 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.866025 0.500001 0"
  "    outer loop"
  "      vertex 82.2191 36.6063 5"
  "      vertex 72.8115 52.9007 0"
  "      vertex 72.8115 52.9007 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.866025 0.500001 0"
  "    outer loop"
  "      vertex 72.8115 52.9007 0"
  "      vertex 82.2191 36.6063 5"
  "      vertex 82.2191 36.6063 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.743145 0.66913 0"
  "    outer loop"
  "      vertex 72.8115 52.9007 5"
  "      vertex 60.2218 66.883 0"
  "      vertex 60.2218 66.883 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.743145 0.66913 0"
  "    outer loop"
  "      vertex 60.2218 66.883 0"
  "      vertex 72.8115 52.9007 5"
  "      vertex 72.8115 52.9007 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.587786 0.809017 -0"
  "    outer loop"
  "      vertex 60.2218 66.883 0"
  "      vertex 45 77.9423 5"
  "      vertex 60.2218 66.883 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.587786 0.809017 0"
  "    outer loop"
  "      vertex 45 77.9423 5"
  "      vertex 60.2218 66.883 0"
  "      vertex 45 77.9423 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.406736 0.913546 -0"
  "    outer loop"
  "      vertex 45 77.9423 0"
  "      vertex 27.8115 85.5951 5"
  "      vertex 45 77.9423 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.406736 0.913546 0"
  "    outer loop"
  "      vertex 27.8115 85.5951 5"
  "      vertex 45 77.9423 0"
  "      vertex 27.8115 85.5951 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.207913 0.978147 -0"
  "    outer loop"
  "      vertex 27.8115 85.5951 0"
  "      vertex 9.40756 89.507 5"
  "      vertex 27.8115 85.5951 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.207913 0.978147 0"
  "    outer loop"
  "      vertex 9.40756 89.507 5"
  "      vertex 27.8115 85.5951 0"
  "      vertex 9.40756 89.507 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 1 -0"
  "    outer loop"
  "      vertex 9.40756 89.507 0"
  "      vertex -9.40756 89.507 5"
  "      vertex 9.40756 89.507 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 1 0"
  "    outer loop"
  "      vertex -9.40756 89.507 5"
  "      vertex 9.40756 89.507 0"
  "      vertex -9.40756 89.507 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.207913 0.978147 0"
  "    outer loop"
  "      vertex -9.40756 89.507 0"
  "      vertex -27.8115 85.5951 5"
  "      vertex -9.40756 89.507 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.207913 0.978147 0"
  "    outer loop"
  "      vertex -27.8115 85.5951 5"
  "      vertex -9.40756 89.507 0"
  "      vertex -27.8115 85.5951 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.406736 0.913546 0"
  "    outer loop"
  "      vertex -27.8115 85.5951 0"
  "      vertex -45 77.9423 5"
  "      vertex -27.8115 85.5951 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.406736 0.913546 0"
  "    outer loop"
  "      vertex -45 77.9423 5"
  "      vertex -27.8115 85.5951 0"
  "      vertex -45 77.9423 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.587786 0.809017 0"
  "    outer loop"
  "      vertex -45 77.9423 0"
  "      vertex -60.2218 66.883 5"
  "      vertex -45 77.9423 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.587786 0.809017 0"
  "    outer loop"
  "      vertex -60.2218 66.883 5"
  "      vertex -45 77.9423 0"
  "      vertex -60.2218 66.883 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.743145 0.66913 0"
  "    outer loop"
  "      vertex -72.8115 52.9007 0"
  "      vertex -60.2218 66.883 5"
  "      vertex -60.2218 66.883 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.743145 0.66913 0"
  "    outer loop"
  "      vertex -60.2218 66.883 5"
  "      vertex -72.8115 52.9007 0"
  "      vertex -72.8115 52.9007 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.866025 0.500001 0"
  "    outer loop"
  "      vertex -82.2191 36.6063 0"
  "      vertex -72.8115 52.9007 5"
  "      vertex -72.8115 52.9007 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.866025 0.500001 0"
  "    outer loop"
  "      vertex -72.8115 52.9007 5"
  "      vertex -82.2191 36.6063 0"
  "      vertex -82.2191 36.6063 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.951056 0.309018 0"
  "    outer loop"
  "      vertex -88.0333 18.7121 0"
  "      vertex -82.2191 36.6063 5"
  "      vertex -82.2191 36.6063 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.951056 0.309018 0"
  "    outer loop"
  "      vertex -82.2191 36.6063 5"
  "      vertex -88.0333 18.7121 0"
  "      vertex -88.0333 18.7121 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.994522 0.104527 0"
  "    outer loop"
  "      vertex -90 -0 0"
  "      vertex -88.0333 18.7121 5"
  "      vertex -88.0333 18.7121 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.994522 0.104527 0"
  "    outer loop"
  "      vertex -88.0333 18.7121 5"
  "      vertex -90 -0 0"
  "      vertex -90 -0 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.994522 -0.104527 0"
  "    outer loop"
  "      vertex -88.0333 -18.7121 0"
  "      vertex -90 -0 5"
  "      vertex -90 -0 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.994522 -0.104527 0"
  "    outer loop"
  "      vertex -90 -0 5"
  "      vertex -88.0333 -18.7121 0"
  "      vertex -88.0333 -18.7121 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.951056 -0.309018 0"
  "    outer loop"
  "      vertex -82.2191 -36.6063 0"
  "      vertex -88.0333 -18.7121 5"
  "      vertex -88.0333 -18.7121 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.951056 -0.309018 0"
  "    outer loop"
  "      vertex -88.0333 -18.7121 5"
  "      vertex -82.2191 -36.6063 0"
  "      vertex -82.2191 -36.6063 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.866025 -0.500001 0"
  "    outer loop"
  "      vertex -72.8115 -52.9007 0"
  "      vertex -82.2191 -36.6063 5"
  "      vertex -82.2191 -36.6063 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.866025 -0.500001 0"
  "    outer loop"
  "      vertex -82.2191 -36.6063 5"
  "      vertex -72.8115 -52.9007 0"
  "      vertex -72.8115 -52.9007 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.743145 -0.66913 0"
  "    outer loop"
  "      vertex -60.2218 -66.883 0"
  "      vertex -72.8115 -52.9007 5"
  "      vertex -72.8115 -52.9007 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.743145 -0.66913 0"
  "    outer loop"
  "      vertex -72.8115 -52.9007 5"
  "      vertex -60.2218 -66.883 0"
  "      vertex -60.2218 -66.883 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.587786 -0.809017 0"
  "    outer loop"
  "      vertex -60.2218 -66.883 0"
  "      vertex -45 -77.9423 5"
  "      vertex -60.2218 -66.883 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.587786 -0.809017 -0"
  "    outer loop"
  "      vertex -45 -77.9423 5"
  "      vertex -60.2218 -66.883 0"
  "      vertex -45 -77.9423 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.406736 -0.913546 0"
  "    outer loop"
  "      vertex -45 -77.9423 0"
  "      vertex -27.8115 -85.5951 5"
  "      vertex -45 -77.9423 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.406736 -0.913546 -0"
  "    outer loop"
  "      vertex -27.8115 -85.5951 5"
  "      vertex -45 -77.9423 0"
  "      vertex -27.8115 -85.5951 0"
  "    endloop"
  "  endfacet"
  "  facet normal -0.207913 -0.978147 0"
  "    outer loop"
  "      vertex -27.8115 -85.5951 0"
  "      vertex -9.40756 -89.507 5"
  "      vertex -27.8115 -85.5951 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0.207913 -0.978147 -0"
  "    outer loop"
  "      vertex -9.40756 -89.507 5"
  "      vertex -27.8115 -85.5951 0"
  "      vertex -9.40756 -89.507 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 -1 0"
  "    outer loop"
  "      vertex -9.40756 -89.507 0"
  "      vertex 9.40756 -89.507 5"
  "      vertex -9.40756 -89.507 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 -1 -0"
  "    outer loop"
  "      vertex 9.40756 -89.507 5"
  "      vertex -9.40756 -89.507 0"
  "      vertex 9.40756 -89.507 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.207913 -0.978147 0"
  "    outer loop"
  "      vertex 9.40756 -89.507 0"
  "      vertex 27.8115 -85.5951 5"
  "      vertex 9.40756 -89.507 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.207913 -0.978147 0"
  "    outer loop"
  "      vertex 27.8115 -85.5951 5"
  "      vertex 9.40756 -89.507 0"
  "      vertex 27.8115 -85.5951 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.406736 -0.913546 0"
  "    outer loop"
  "      vertex 27.8115 -85.5951 0"
  "      vertex 45 -77.9423 5"
  "      vertex 27.8115 -85.5951 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.406736 -0.913546 0"
  "    outer loop"
  "      vertex 45 -77.9423 5"
  "      vertex 27.8115 -85.5951 0"
  "      vertex 45 -77.9423 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.587786 -0.809017 0"
  "    outer loop"
  "      vertex 45 -77.9423 0"
  "      vertex 60.2218 -66.883 5"
  "      vertex 45 -77.9423 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.587786 -0.809017 0"
  "    outer loop"
  "      vertex 60.2218 -66.883 5"
  "      vertex 45 -77.9423 0"
  "      vertex 60.2218 -66.883 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.743145 -0.66913 0"
  "    outer loop"
  "      vertex 60.2218 -66.883 5"
  "      vertex 72.8115 -52.9007 0"
  "      vertex 72.8115 -52.9007 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.743145 -0.66913 0"
  "    outer loop"
  "      vertex 72.8115 -52.9007 0"
  "      vertex 60.2218 -66.883 5"
  "      vertex 60.2218 -66.883 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.866025 -0.500001 0"
  "    outer loop"
  "      vertex 72.8115 -52.9007 5"
  "      vertex 82.2191 -36.6063 0"
  "      vertex 82.2191 -36.6063 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.866025 -0.500001 0"
  "    outer loop"
  "      vertex 82.2191 -36.6063 0"
  "      vertex 72.8115 -52.9007 5"
  "      vertex 72.8115 -52.9007 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.951056 -0.309018 0"
  "    outer loop"
  "      vertex 82.2191 -36.6063 5"
  "      vertex 88.0333 -18.7121 0"
  "      vertex 88.0333 -18.7121 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.951056 -0.309018 0"
  "    outer loop"
  "      vertex 88.0333 -18.7121 0"
  "      vertex 82.2191 -36.6063 5"
  "      vertex 82.2191 -36.6063 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0.994522 -0.104527 0"
  "    outer loop"
  "      vertex 88.0333 -18.7121 5"
  "      vertex 90 0 0"
  "      vertex 90 0 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0.994522 -0.104527 0"
  "    outer loop"
  "      vertex 90 0 0"
  "      vertex 88.0333 -18.7121 5"
  "      vertex 88.0333 -18.7121 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 88.0333 -18.7121 0"
  "      vertex 88.0333 18.7121 0"
  "      vertex 90 0 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 82.2191 -36.6063 0"
  "      vertex 88.0333 18.7121 0"
  "      vertex 88.0333 -18.7121 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 82.2191 -36.6063 0"
  "      vertex 82.2191 36.6063 0"
  "      vertex 88.0333 18.7121 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 72.8115 -52.9007 0"
  "      vertex 82.2191 36.6063 0"
  "      vertex 82.2191 -36.6063 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 72.8115 -52.9007 0"
  "      vertex 72.8115 52.9007 0"
  "      vertex 82.2191 36.6063 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 60.2218 -66.883 0"
  "      vertex 72.8115 52.9007 0"
  "      vertex 72.8115 -52.9007 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 60.2218 -66.883 0"
  "      vertex 60.2218 66.883 0"
  "      vertex 72.8115 52.9007 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 45 -77.9423 0"
  "      vertex 60.2218 66.883 0"
  "      vertex 60.2218 -66.883 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 45 -77.9423 0"
  "      vertex 45 77.9423 0"
  "      vertex 60.2218 66.883 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 27.8115 -85.5951 0"
  "      vertex 45 77.9423 0"
  "      vertex 45 -77.9423 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 27.8115 -85.5951 0"
  "      vertex 27.8115 85.5951 0"
  "      vertex 45 77.9423 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 9.40756 -89.507 0"
  "      vertex 27.8115 85.5951 0"
  "      vertex 27.8115 -85.5951 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex 9.40756 -89.507 0"
  "      vertex 9.40756 89.507 0"
  "      vertex 27.8115 85.5951 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -9.40756 -89.507 0"
  "      vertex 9.40756 89.507 0"
  "      vertex 9.40756 -89.507 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -9.40756 -89.507 0"
  "      vertex -9.40756 89.507 0"
  "      vertex 9.40756 89.507 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -27.8115 -85.5951 0"
  "      vertex -9.40756 89.507 0"
  "      vertex -9.40756 -89.507 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -27.8115 -85.5951 0"
  "      vertex -27.8115 85.5951 0"
  "      vertex -9.40756 89.507 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -45 -77.9423 0"
  "      vertex -27.8115 85.5951 0"
  "      vertex -27.8115 -85.5951 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -45 -77.9423 0"
  "      vertex -45 77.9423 0"
  "      vertex -27.8115 85.5951 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -60.2218 -66.883 0"
  "      vertex -45 77.9423 0"
  "      vertex -45 -77.9423 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -60.2218 -66.883 0"
  "      vertex -60.2218 66.883 0"
  "      vertex -45 77.9423 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -72.8115 -52.9007 0"
  "      vertex -60.2218 66.883 0"
  "      vertex -60.2218 -66.883 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -72.8115 -52.9007 0"
  "      vertex -72.8115 52.9007 0"
  "      vertex -60.2218 66.883 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -82.2191 -36.6063 0"
  "      vertex -72.8115 52.9007 0"
  "      vertex -72.8115 -52.9007 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -82.2191 -36.6063 0"
  "      vertex -82.2191 36.6063 0"
  "      vertex -72.8115 52.9007 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -88.0333 -18.7121 0"
  "      vertex -82.2191 36.6063 0"
  "      vertex -82.2191 -36.6063 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 -1"
  "    outer loop"
  "      vertex -88.0333 -18.7121 0"
  "      vertex -88.0333 18.7121 0"
  "      vertex -82.2191 36.6063 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 -0 -1"
  "    outer loop"
  "      vertex -88.0333 18.7121 0"
  "      vertex -88.0333 -18.7121 0"
  "      vertex -90 -0 0"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 88.0333 18.7121 5"
  "      vertex 88.0333 -18.7121 5"
  "      vertex 90 0 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 82.2191 36.6063 5"
  "      vertex 88.0333 -18.7121 5"
  "      vertex 88.0333 18.7121 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 82.2191 36.6063 5"
  "      vertex 82.2191 -36.6063 5"
  "      vertex 88.0333 -18.7121 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 72.8115 52.9007 5"
  "      vertex 82.2191 -36.6063 5"
  "      vertex 82.2191 36.6063 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 72.8115 52.9007 5"
  "      vertex 72.8115 -52.9007 5"
  "      vertex 82.2191 -36.6063 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 60.2218 66.883 5"
  "      vertex 72.8115 -52.9007 5"
  "      vertex 72.8115 52.9007 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 60.2218 66.883 5"
  "      vertex 60.2218 -66.883 5"
  "      vertex 72.8115 -52.9007 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 45 77.9423 5"
  "      vertex 60.2218 -66.883 5"
  "      vertex 60.2218 66.883 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 45 77.9423 5"
  "      vertex 45 -77.9423 5"
  "      vertex 60.2218 -66.883 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 27.8115 85.5951 5"
  "      vertex 45 -77.9423 5"
  "      vertex 45 77.9423 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 27.8115 85.5951 5"
  "      vertex 27.8115 -85.5951 5"
  "      vertex 45 -77.9423 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 9.40756 89.507 5"
  "      vertex 27.8115 -85.5951 5"
  "      vertex 27.8115 85.5951 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex 9.40756 89.507 5"
  "      vertex 9.40756 -89.507 5"
  "      vertex 27.8115 -85.5951 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0 0 1"
  "    outer loop"
  "      vertex -9.40756 89.507 5"
  "      vertex 9.40756 -89.507 5"
  "      vertex 9.40756 89.507 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex -9.40756 89.507 5"
  "      vertex -9.40756 -89.507 5"
  "      vertex 9.40756 -89.507 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0 0 1"
  "    outer loop"
  "      vertex -27.8115 85.5951 5"
  "      vertex -9.40756 -89.507 5"
  "      vertex -9.40756 89.507 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex -27.8115 85.5951 5"
  "      vertex -27.8115 -85.5951 5"
  "      vertex -9.40756 -89.507 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0 0 1"
  "    outer loop"
  "      vertex -45 77.9423 5"
  "      vertex -27.8115 -85.5951 5"
  "      vertex -27.8115 85.5951 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex -45 77.9423 5"
  "      vertex -45 -77.9423 5"
  "      vertex -27.8115 -85.5951 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0 0 1"
  "    outer loop"
  "      vertex -60.2218 66.883 5"
  "      vertex -45 -77.9423 5"
  "      vertex -45 77.9423 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex -60.2218 66.883 5"
  "      vertex -60.2218 -66.883 5"
  "      vertex -45 -77.9423 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0 0 1"
  "    outer loop"
  "      vertex -72.8115 52.9007 5"
  "      vertex -60.2218 -66.883 5"
  "      vertex -60.2218 66.883 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex -72.8115 52.9007 5"
  "      vertex -72.8115 -52.9007 5"
  "      vertex -60.2218 -66.883 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0 0 1"
  "    outer loop"
  "      vertex -82.2191 36.6063 5"
  "      vertex -72.8115 -52.9007 5"
  "      vertex -72.8115 52.9007 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex -82.2191 36.6063 5"
  "      vertex -82.2191 -36.6063 5"
  "      vertex -72.8115 -52.9007 5"
  "    endloop"
  "  endfacet"
  "  facet normal -0 0 1"
  "    outer loop"
  "      vertex -88.0333 18.7121 5"
  "      vertex -82.2191 -36.6063 5"
  "      vertex -82.2191 36.6063 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 0 1"
  "    outer loop"
  "      vertex -88.0333 18.7121 5"
  "      vertex -88.0333 -18.7121 5"
  "      vertex -82.2191 -36.6063 5"
  "    endloop"
  "  endfacet"
  "  facet normal 0 -0 1"
  "    outer loop"
  "      vertex -88.0333 -18.7121 5"
  "      vertex -88.0333 18.7121 5"
  "      vertex -90 -0 5"
  "    endloop"
  "  endfacet"
  "endsolid OpenSCAD_Model");

#endif // NAILCLIPPER_TEST_STL_H