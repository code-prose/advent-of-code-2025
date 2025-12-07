#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>


using ReadVec = std::vector< std::vector<int> >;
void pt1(ReadVec &InputVec);
void pt2(std::vector<std::string> &lines);
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
  pt2(lines);
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

void pt2(std::vector<std::string> &lines) {
    long long grandTotal = 0;
    int operatorRow = lines.size() - 1;

    size_t maxLen = 0;
    for (const auto &line : lines) {
        maxLen = std::max(maxLen, line.length());
    }
    for (auto &line : lines) {
        while (line.length() < maxLen) {
            line += ' ';
        }
    }

    std::vector<long long> problemNumbers;
    char currentOp = ' ';
    bool inProblem = false;

    for (int col = maxLen - 1; col >= -1; col--) {
        bool isSpaceColumn = true;

        if (col >= 0) {
            for (int row = 0; row <= operatorRow; row++) {
                if (lines[row][col] != ' ') {
                    isSpaceColumn = false;
                    break;
                }
            }

            if (!isSpaceColumn) {
                char op = lines[operatorRow][col];
                if (op != ' ' && (op == '+' || op == '*')) {
                    if (!inProblem) {
                        currentOp = op;
                        inProblem = true;
                    }
                }

                std::string digitString = "";
                for (int row = 0; row < operatorRow; row++) {
                    if (lines[row][col] != ' ') {
                        digitString += lines[row][col];
                    }
                }

                if (!digitString.empty()) {
                    long long num = std::stoll(digitString);
                    problemNumbers.push_back(num);
                }
            }
        }

        if ((isSpaceColumn || col == -1) && inProblem) {
            long long result = 0;

            if (currentOp == '*') {
                result = 1;
                for (auto num : problemNumbers) {
                    result *= num;
                }
            } else if (currentOp == '+') {
                result = 0;
                for (auto num : problemNumbers) {
                    result += num;
                }
            }
            grandTotal += result;

            problemNumbers.clear();
            currentOp = ' ';
            inProblem = false;
        }
    }

    std::cout << grandTotal << std::endl;
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

