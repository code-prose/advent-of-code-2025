#include <fstream>
#include <iostream>
#include <string>

void pt1(std::vector< std::vector<char> > &InputVectors); 


int main() {
  std::vector< std::vector<char> > InputVectors;
  std::ifstream inputFile("./test_input.txt");
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
}

void pt1(std::vector< std::vector<char> > &InputVectors) {
  int total_count = 0;
  for (size_t i = 0; i < InputVectors.size(); i++) {
    int count = 0;
    for (size_t j = 0; j < InputVectors[i].size(); j++) {
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
      if (count >= 4) {
                total_count += 1;
      }
    }
  }
  std::cout << total_count << std::endl;
}
