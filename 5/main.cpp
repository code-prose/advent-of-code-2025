#include <fstream>
#include <iostream>
#include <string>


using ReadVec = std::vector<std::string>;
using RangeVec = std::vector< std::tuple<long long, long long> >;
using FreshVec = std::vector<long long>;

void pt1(RangeVec &rangeVector, FreshVec &freshVector);
void pt2(RangeVec &rangeVector, FreshVec &freshVector);
void parseInput(ReadVec &InVec, RangeVec &rangeVector, FreshVec &freshVec);


int main() {
  ReadVec InputVector;
  std::ifstream inputFile("./test_input.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }
  std::string line;
  while (std::getline(inputFile, line)) {
    std::string temp;
    for (auto &i : line) {
      temp.push_back(i);
    }
    InputVector.push_back(temp);
  }
  RangeVec rangeVector;
  FreshVec freshVector;

  parseInput(InputVector, rangeVector, freshVector);
  pt1(rangeVector, freshVector);
  pt2(rangeVector, freshVector);
}


void parseInput(ReadVec &InVec, RangeVec &rangeVector, FreshVec &freshVector) {
    for (auto &str : InVec) {
        if (str.empty()) {
            continue;
        }
        size_t pos = str.find("-");
        if (pos == std::string::npos) {
            freshVector.push_back(std::stoll(str));
        } else {
            long long start = std::stoll(str.substr(0, pos));
            long long end = std::stoll(str.substr(pos + 1));
            rangeVector.push_back(std::make_tuple(start, end));
        }
    }
}

void pt1(RangeVec &rangeVector, FreshVec &freshVector) {
    int freshCount = 0;

    for (auto ingredientID : freshVector) {
        bool isFresh = false;
        for (auto &range : rangeVector) {
            long long start = std::get<0>(range);
            long long end = std::get<1>(range);

            if (ingredientID >= start && ingredientID <= end) {
                isFresh = true;
                break;
            }
        }

        if (isFresh) {
            freshCount++;
        }
    }

    std::cout << "Part 1: " << freshCount << " ingredient IDs are fresh" << std::endl;
}

void pt2(RangeVec & /* rangeVector */, FreshVec & /* freshVector */) {
    // Part 2 to be implemented
    return;
}
