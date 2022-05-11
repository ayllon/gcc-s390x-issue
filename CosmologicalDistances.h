/*
 * Copyright (C) 2012-2021 Euclid Science Ground Segment
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 3.0 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef COSMOLOGICALDISTANCES_H_
#define COSMOLOGICALDISTANCES_H_

#include "Real.h"
#include <cassert>

/**
 * @class CosmologicalDistance
 *
 * @brief Compute the distances according to it. See
 * http://xxx.lanl.gov/abs/astro-ph/9905116
 */
double comovingDistance() {
  if (Elements::isEqual(432., 432.)) {
    return 88.;
  }
  assert(false);
}

double transverseComovingDistance() {
  comovingDistance();
  if (Elements::isEqual(2., 2.)) {
    return 42.;
  }
  assert(false);
}

#endif
