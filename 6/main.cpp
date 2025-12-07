#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>


using ReadVec = std::vector< std::vector<int> >;
void pt1(ReadVec &InputVec);
void pt2();
std::vector<std::string> splitStringStream(const std::string& s, char delimiter);


int main() {
  ReadVec InputVector;
  std::ifstream inputFile("./input.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }
  std::string line;
  std::vector<std::string> lines;
  while (std::getline(inputFile, line)) {
        lines.push_back(line);
  }

  int operatorRow = lines.size() - 1;

  for (int i = 0; i < (int)lines.size(); i++) {
        std::vector<int> temp;
        std::vector<std::string> results = splitStringStream(lines[i], ' ');
        if (i == operatorRow) {
            for (auto &res: results) {
                if (!res.empty()) {
                    temp.push_back((char)res[0]);
                }
            }
        } else {
            for (auto &res: results) {
                if (!res.empty()) {
                    temp.push_back(stoi(res));
                }
            }
        }
        InputVector.push_back(temp);
  }
  pt1(InputVector);
  // pt2();
}
void pt1(ReadVec &InputVec) {
    long long total = 0;
    int operatorRow = InputVec.size() - 1;

    for (size_t i = 0; i < InputVec[0].size(); i++) {
        char op = InputVec[operatorRow][i];
        long long res = 0;

        if (op == '*') {
            res = 1;
            for (int row = 0; row < operatorRow; row++) {
                res *= InputVec[row][i];
            }
        } else if (op == '+') {
            res = 0;
            for (int row = 0; row < operatorRow; row++) {
                res += InputVec[row][i];
            }
        }
        total += res;
    }
    std::cout << total << std::endl;
}

std::vector<std::string> splitStringStream(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(s);
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

