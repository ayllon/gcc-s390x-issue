CXXFLAGS?=-flto=auto -ffat-lto-objects -g
LDFLAGS?=-Wl,-z,relro -Wl,--as-needed  -Wl,-z,now

all: test-o1 test-o2

test-o1: CosmologicalParameters.cpp CosmologicalDistances.cpp main.cpp
	$(CXX) $(CXXFLAGS) -O1 $^ -o $@

test-o2: CosmologicalParameters.cpp CosmologicalDistances.cpp main.cpp
	$(CXX) $(CXXFLAGS) -O2 $^ -o $@

clean:
	rm -f test-o? *.o?

.PHONY: all clean

