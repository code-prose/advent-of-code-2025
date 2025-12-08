#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
#include <set>


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
        std::cout << line << std::endl;
  }
  pt1(InputVector);
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

int countPaths(const ReadVec& grid, int row, int col, std::set<std::pair<int, int>>& pathVisited) {
    if (col < 0 || col >= (int)grid[0].size() || row >= (int)grid.size()) {
        return 1;  // This is one complete timeline/path
    }

    if (pathVisited.count({row, col})) {
        return 0;
    }
    pathVisited.insert({row, col});

    char cell = grid[row][col];
    int totalPaths = 0;

    if (cell == '.' || cell == 'S' || cell == '|') {
        totalPaths = countPaths(grid, row + 1, col, pathVisited);
    }
    else if (cell == '^') {
        std::set<std::pair<int, int>> leftPath = pathVisited;
        std::set<std::pair<int, int>> rightPath = pathVisited;

        totalPaths = countPaths(grid, row + 1, col - 1, leftPath) +
                     countPaths(grid, row + 1, col + 1, rightPath);
    }

    return totalPaths;
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

    std::set<std::pair<int, int>> pathVisited;
    int count = countPaths(InputVector, startRow, startCol, pathVisited);

    std::cout << count << std::endl;
}
