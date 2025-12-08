#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>


using ReadVec = std::vector<std::string>;
void pt1(ReadVec InputVector);
// void pt2();


int main() {
  ReadVec InputVector;
  std::ifstream inputFile("./input.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }
  std::string line;
  while (std::getline(inputFile, line)) {
        InputVector.push_back(line);
        std::cout << line << std::endl;
  }
  pt1(InputVector);
  // pt2();
}

void pt1(ReadVec InputVector) {
    int count = 0;
    for (size_t i = 0; i < InputVector.size(); i++) {
         for (size_t j = 0; j < InputVector[i].size(); j++) {
            if (InputVector[i][j] == '|' or InputVector[i][j] == 'S') {
                if (i < InputVector.size() - 1) {
                    if (InputVector[i + 1][j] == '^') {
                        count++;
                        if (j > 0) {
                            InputVector[i + 1][j - 1] = '|';
                        }
                        if (j < InputVector[i + 1].size() - 1) {
                            InputVector[i + 1][j + 1] = '|';
                        }
                    } else {
                       InputVector[i + 1][j] = '|';
                    }   
                }
            }
        }
    }
    for (auto &y : InputVector) {
        for (auto &t: y) {
            std::cout << t;
        }
        std::cout << std::endl;
    }
    std::cout << count << std::endl;
    return;
}
