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
        size_t pos = str.find("-");
        if (pos == std::string::npos) {
            freshVector.push_back(str);
        } else {
            std::tuple<long long, long long> temp(str.substr(0, pos), str.substr(pos + 1));
            rangeVector.push_back(temp);
        }
    }
}

void pt1(RangeVec &rangeVector, FreshVec &freshVector) {
    std::cout << rangeVector[0] << " " << freshVector[0] << std::endl;
    return;
}

void pt2(RangeVec &rangeVector, FreshVec &freshVector) {
    std::cout << rangeVector[0] << " " << freshVector[0] << std::endl;
    return;
}
