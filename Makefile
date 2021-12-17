CXXFLAGS?=-O2 -flto=auto -ffat-lto-objects
LDFLAGS?=-Wl,-z,relro -Wl,--as-needed  -Wl,-z,now

all: test

%.o: %.cpp foo.h
	$(CXX) -c $(CXXFLAGS) $< -o $@

test: CosmologicalParameters.o CosmologicalDistances.o main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -f test *.o

