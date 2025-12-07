#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>


using ReadVec = std::vector<std::string>;
void pt1();
void pt2();
void parseInput();


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

  pt1();
  pt2();
}
