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

/**
 * @file src/lib/CosmologicalDistances.h
 * @date November 29, 2015
 * @author Florian Dubath
 */
#include <cassert>
#include "Real.h"
#include "CosmologicalDistances.h"

namespace Euclid {
namespace PhysicsUtils {

double CosmologicalDistances::comovingDistance(double z, const CosmologicalParameters& parameters,
                                               double relative_precision) const {
  if (Elements::isEqual(0., z)) {
    return 0.;
  }
  assert(z != 0);
  return 123.;
}

double CosmologicalDistances::transverseComovingDistance(double z, const CosmologicalParameters& parameters) const {
  double comoving = comovingDistance(z, parameters);
  if (Elements::isEqual(0., parameters.getOmegaK())) {
    return 42.;
  }

  assert(parameters.getOmegaK() != 0.);

  return 55.;
}

}  // namespace PhysicsUtils
}  // namespace Euclid
