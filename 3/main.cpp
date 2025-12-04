#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

void pt1(std::vector< std::vector<int> > &inputVectors);
void pt2(std::vector< std::vector<int> > &InputVectors);
long long recursiveFind(std::vector<int> &vec, int remaining, size_t startingIdx);
long long intPower(int base, int exp); 


int main() {
  std::vector< std::vector<int> > InputVectors;
  std::ifstream inputFile("./input.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }
  std::string line;
  while (std::getline(inputFile, line)) {
    std::vector<int> temp;
    for (auto &i : line) {
      temp.push_back(i - '0');
    }
    InputVectors.push_back(temp);
  }
  inputFile.close();
  pt1(InputVectors);
}


void pt1(std::vector< std::vector<int> > &InputVectors) {
  long long output = 0;
  int highest = 0;
  int SecondHighest = 0;
  size_t HighestIndex = 0;

  for (auto &vec : InputVectors) {
    HighestIndex = 0;
    highest = 0;
    SecondHighest = 0;

    for (size_t i = 0; i < vec.size() - 1; i++) {
      int t_highest = highest;
      highest = std::max(highest, vec[i]);
      if (highest != t_highest) {
        HighestIndex = i + 1;
      }
    }
    for (size_t j = HighestIndex; j < vec.size(); j++) {
      SecondHighest = std::max(SecondHighest, vec[j]);
    }
    int num = highest * 10 + SecondHighest;
    output += num;
  }
  std::cout << output << std::endl;
}


void pt2(std::vector< std::vector<int> > &InputVectors) {
    long long result = 0;
    for (auto &vec : InputVectors) {
         result += recursiveFind(vec, 12, 0);
    }
    std::cout << result << std::endl;
}


long long recursiveFind(std::vector<int> &vec, int remaining, size_t startingIdx) {
    if (remaining == 0) {
        return 0;
    }
    int highest = 0;
    size_t HighestIdx = startingIdx;

    for (size_t i = startingIdx; i < vec.size() - remaining + 1; i++) {
        int t_highest = highest;
        highest = std::max(highest, vec[i]);
        if (highest != t_highest) {
            HighestIdx = i;
        }
    }
    return ((long long)highest * intPower(10, remaining - 1)) + recursiveFind(vec, remaining - 1, HighestIdx + 1);
}

long long intPower(int base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}
