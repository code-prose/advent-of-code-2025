CXX = g++
CXXFLAGS = -std=c++23 -Wall -Werror -Wextra
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
UTILS_DIR = utils

TARGET = day1
SOURCES = main.cpp $(UTILS_DIR)/dial.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)	

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJECTS) $(TARGETS)
