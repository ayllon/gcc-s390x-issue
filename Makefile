CXXFLAGS?=-flto -g -save-temps
LDFLAGS?=-Wl,-z,relro -Wl,--as-needed  -Wl,-z,now

all: test-o1 test-o2

test-o1: main.cpp
	$(CXX) $(CXXFLAGS) -O1 $^ -o $@

test-o2: main.cpp
	$(CXX) $(CXXFLAGS) -O2 $^ -o $@

clean:
	rm -f test-o? *.o?

.PHONY: all clean

