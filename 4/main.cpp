#include <fstream>
#include <iostream>
#include <string>


using InVec = std::vector< std::vector<char> >;

void pt1(InVec &InputVectors); 
void pt2(InVec &InputVectors);
InVec pt2Helper(InVec InputVectors, int &totalCount);


int main() {
  InVec InputVectors;
  std::ifstream inputFile("./input.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }
  std::string line;
  while (std::getline(inputFile, line)) {
    std::vector<char> temp;
    for (auto &i : line) {
      temp.push_back(i);
    }
    InputVectors.push_back(temp);
  }
  pt1(InputVectors);
  pt2(InputVectors);
}

void pt1(InVec &InputVectors) {
  int total_count = 0;
  for (size_t i = 0; i < InputVectors.size(); i++) {
    for (size_t j = 0; j < InputVectors[i].size(); j++) {
      if (InputVectors[i][j] != '@') continue;
      int count = 0;
      // straight left
      if (j > 0) {
        if (InputVectors[i][j - 1] == '@') {
          count++;
        }
      }
      // up left
      if (j > 0 && i > 0) {
        if (InputVectors[i - 1][j - 1] == '@') {
          count++;
        }
      }
      // down left
      if (j > 0 && i < InputVectors.size() - 1) {
        if (InputVectors[i + 1][j - 1] == '@') {
          count++;
        }
      }
      // straight down
      if (i < InputVectors.size() - 1) {
        if (InputVectors[i + 1][j] == '@') {
          count++;
        }
      }
      // straight up
      if (i > 0) {
        if (InputVectors[i - 1][j] == '@') {
          count++;
        }
      }
      // straight right
      if (j < InputVectors[i].size() - 1) {
        if (InputVectors[i][j + 1] == '@') {
          count++;
        }
      }
      // up right
      if (j < InputVectors[i].size() - 1 && i > 0) {
        if (InputVectors[i - 1][j + 1] == '@') {
          count++;
        }
      }
      // down right
      if (j < InputVectors[i].size() - 1 && i < InputVectors.size() - 1) {
        if (InputVectors[i + 1][j + 1] == '@') {
          count++;
        }
      }
      if (count < 4) {
                total_count += 1;
      }
    }
  }
  std::cout << total_count << std::endl;
}


void pt2(InVec &InputVectors) {
    int totalCount = 0;
    int returnedCount = 0;
    InVec reuseVec = pt2Helper(InputVectors, returnedCount);
    totalCount += returnedCount;
    while (returnedCount != 0) {
        returnedCount = 0;
        reuseVec = pt2Helper(reuseVec, returnedCount);
        totalCount += returnedCount;
    }
    std::cout << totalCount << std::endl;

}

InVec pt2Helper(InVec InputVectors, int &totalCount) {
  InVec toReturn = InputVectors;
  for (size_t i = 0; i < InputVectors.size(); i++) {
    for (size_t j = 0; j < InputVectors[i].size(); j++) {
      if (InputVectors[i][j] != '@') continue;
      int count = 0;
      // straight left
      if (j > 0) {
        if (InputVectors[i][j - 1] == '@') {
          count++;
        }
      }
      // up left
      if (j > 0 && i > 0) {
        if (InputVectors[i - 1][j - 1] == '@') {
          count++;
        }
      }
      // down left
      if (j > 0 && i < InputVectors.size() - 1) {
        if (InputVectors[i + 1][j - 1] == '@') {
          count++;
        }
      }
      // straight down
      if (i < InputVectors.size() - 1) {
        if (InputVectors[i + 1][j] == '@') {
          count++;
        }
      }
      // straight up
      if (i > 0) {
        if (InputVectors[i - 1][j] == '@') {
          count++;
        }
      }
      // straight right
      if (j < InputVectors[i].size() - 1) {
        if (InputVectors[i][j + 1] == '@') {
          count++;
        }
      }
      // up right
      if (j < InputVectors[i].size() - 1 && i > 0) {
        if (InputVectors[i - 1][j + 1] == '@') {
          count++;
        }
      }
      // down right
      if (j < InputVectors[i].size() - 1 && i < InputVectors.size() - 1) {
        if (InputVectors[i + 1][j + 1] == '@') {
          count++;
        }
      }
      if (count < 4) {
        totalCount += 1;
        toReturn[i][j] = '.';
      }
    }
  }
  return toReturn;
}
