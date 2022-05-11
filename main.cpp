#include "CosmologicalDistances.h"

using namespace Euclid::PhysicsUtils;

int main() {
    CosmologicalDistances distances{};
    [[maybe_unused]] double push_stack[] = {55., 66., 77.};

    return static_cast<int>(distances.transverseComovingDistance(1.5));
}
