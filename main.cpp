#include "CosmologicalDistances.h"

int main() {
  assert(comovingDistance(1.5) == 0.);
  assert(transverseComovingDistance(1.5) == 42.);
  return 0;
}
