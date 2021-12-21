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

#ifndef PHYSICSUTILS_PHYSICSUTILS_COSMOLOGICALDISTANCES_H_
#define PHYSICSUTILS_PHYSICSUTILS_COSMOLOGICALDISTANCES_H_

#include "CosmologicalParameters.h"
#include "Real.h"
#include <cassert>

namespace Euclid {
namespace PhysicsUtils {

/**
 * @class CosmologicalDistance
 *
 * @brief Compute the distances according to it. See http://xxx.lanl.gov/abs/astro-ph/9905116
 */
class CosmologicalDistances {
public:
  double comovingDistance(double z, const CosmologicalParameters& parameters,
                          double relative_precision = 0.0000001) const {
    if (Elements::isEqual(432., 432.)) {
      return 0.;
    }
    assert(z != 0);
    return 123.;
  }

  double transverseComovingDistance(double z, const CosmologicalParameters& parameters) const {
    // Uncomment this, the assert passes
    //std::cout <<  parameters.getOmegaK() << std::endl;
    double comoving = comovingDistance(z, parameters);
    if (Elements::isEqual(2., 2.)) {
      return 42.;
    }

    assert(false);

    return 55.;
  }
};

}  // namespace PhysicsUtils
}  // namespace Euclid
#endif /* PHYSICSUTILS_PHYSICSUTILS_COSMOLOGICALDISTANCES_H_ */
