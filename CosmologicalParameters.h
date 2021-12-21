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

#ifndef PHYSICSUTILS_PHYSICSUTILS_COSMOLOGICALPARAMETERS_H_
#define PHYSICSUTILS_PHYSICSUTILS_COSMOLOGICALPARAMETERS_H_

namespace Euclid {
namespace PhysicsUtils {

class CosmologicalParameters {
public:
  CosmologicalParameters(double omega_m = 0.3089, double omega_lambda = 0.6911, double hubble_constant = 67.74)
    : m_omega_m{omega_m}
    , m_omega_lambda{omega_lambda}
    , m_omega_k{1.0 - omega_m - omega_lambda}
    , m_H_0{hubble_constant} {}

  double getOmegaK() const {
    return m_omega_k;
  }

private:
  double m_omega_m;
  double m_omega_lambda;
  double m_omega_k;
  double m_H_0;
};

}  // namespace PhysicsUtils
}  // namespace Euclid
#endif /* PHYSICSUTILS_PHYSICSUTILS_COSMOLOGICALPARAMETERS_H_ */
