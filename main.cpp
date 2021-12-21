#include "CosmologicalParameters.h"
#include "CosmologicalDistances.h"
#include "Real.h"
#include <cstdio>

using namespace Euclid::PhysicsUtils;

int main() {
    CosmologicalParameters parameters_2{0.2, 0.8, 77.0};
    CosmologicalDistances distances{};
    double push_stack[] = {55., 66., 77.};

    printf("%.2f %d\n", distances.transverseComovingDistance(1.5, parameters_2), push_stack[3]);
}
