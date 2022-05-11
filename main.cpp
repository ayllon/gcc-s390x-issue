#include "CosmologicalDistances.h"

int main() {
  assert(comovingDistance(1.5) == 0.);
  return static_cast<int>(transverseComovingDistance(1.5));
}
