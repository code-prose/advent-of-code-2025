CXX = g++
CXXFLAGS = -std=c++23 -Wall -Werror -Wextra

TARGETS = part1 part2

all: $(TARGETS)

part1: part1.o
	$(CXX) $(CXXFLAGS) part1.o -o part1

part2: part2.o
	$(CXX) $(CXXFLAGS) part2.o -o part2

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGETS)

.PHONY: all clean
