#include "CosmologicalDistances.h"

int main() {
  assert(comovingDistance() == 88.);
  assert(transverseComovingDistance() == 42.);
  return 0;
}
