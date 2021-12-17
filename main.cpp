#include <iostream>
#include "CosmologicalParameters.h"
#include "CosmologicalDistances.h"
#include "Real.h"

using namespace Euclid::PhysicsUtils;

int main() {
	CosmologicalParameters parameters_2{0.2, 1.0 - 0.2, 77.0};
	CosmologicalDistances distances{};

	std::cout << "Should not be nan: " <<  distances.transverseComovingDistance(1.5, parameters_2) << std::endl;
}
