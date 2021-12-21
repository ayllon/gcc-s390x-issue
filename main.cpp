#include "CosmologicalParameters.h"
#include "CosmologicalDistances.h"
#include "Real.h"

using namespace Euclid::PhysicsUtils;

int main() {
    CosmologicalParameters parameters_2{0.2, 0.8, 77.0};
    CosmologicalDistances distances{};
    double push_stack[] = {55., 66., 77.};

    return static_cast<int>(distances.transverseComovingDistance(1.5, parameters_2));
}
