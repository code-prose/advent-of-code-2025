#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
#include <set>
#include <map>


using ReadVec = std::vector<std::string>;
void pt1(ReadVec InputVector);
void pt2(ReadVec InputVector);


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
  }
  // pt1(InputVector);
  pt2(InputVector);
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

// Count number of distinct paths from (row, col) to bottom
// Using memoization to avoid recomputing
long long countPaths(const ReadVec& grid, int row, int col,
                     std::map<std::pair<int, int>, long long>& memo) {
    // Out of bounds
    if (col < 0 || col >= (int)grid[0].size()) {
        return 0;
    }
    if (row >= (int)grid.size()) {
        return 1;  // reached bottom - this is one complete path
    }

    // Check memoization
    auto key = std::make_pair(row, col);
    if (memo.count(key)) {
        return memo[key];
    }

    char cell = grid[row][col];
    long long result = 0;

    if (cell == '.' || cell == 'S' || cell == '|') {
        result = countPaths(grid, row + 1, col, memo);
    }
    else if (cell == '^') {
        result = countPaths(grid, row + 1, col - 1, memo) +
                 countPaths(grid, row + 1, col + 1, memo);
    }

    memo[key] = result;
    return result;
}

void pt2(ReadVec InputVector) {
    int startRow = -1, startCol = -1;
    for (size_t i = 0; i < InputVector.size(); i++) {
        for (size_t j = 0; j < InputVector[i].size(); j++) {
            if (InputVector[i][j] == 'S') {
                startRow = i;
                startCol = j;
                break;
            }
        }
        if (startRow != -1) break;
    }

    std::map<std::pair<int, int>, long long> memo;
    long long count = countPaths(InputVector, startRow, startCol, memo);

    std::cout << count << std::endl;
}
