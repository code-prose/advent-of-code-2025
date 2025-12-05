#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>


using ReadVec = std::vector<std::string>;
using RangeVec = std::vector< std::tuple<long long, long long> >;
using FreshVec = std::vector<long long>;

void pt1(RangeVec &rangeVector, FreshVec &freshVector);
void pt2(RangeVec &rangeVector, FreshVec &freshVector);
void parseInput(ReadVec &InVec, RangeVec &rangeVector, FreshVec &freshVec);


int main() {
  ReadVec InputVector;
  std::ifstream inputFile("./input.txt");
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

    std::cout << freshCount <<  std::endl;
}

void pt2(RangeVec &rangeVector) {
    std::sort(rangeVector.begin(), rangeVector.end(),
              [](const auto &a, const auto &b) {
                  return std::get<0>(a) < std::get<0>(b);
              });

    RangeVec merged;
    merged.push_back(rangeVector[0]);

    for (size_t i = 1; i < rangeVector.size(); i++) {
        long long currentStart = std::get<0>(rangeVector[i]);
        long long currentEnd = std::get<1>(rangeVector[i]);
        long long lastEnd = std::get<1>(merged.back());

        if (currentStart <= lastEnd + 1) {
            std::get<1>(merged.back()) = std::max(lastEnd, currentEnd);
        } else {
            merged.push_back(rangeVector[i]);
        }
    }

    long long totalCount = 0;
    for (auto &range : merged) {
        long long start = std::get<0>(range);
        long long end = std::get<1>(range);
        totalCount += (end - start + 1);
    }
    std::cout << totalCount << std::endl;
}
