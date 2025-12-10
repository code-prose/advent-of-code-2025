#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using ReadVec = std::vector<std::pair<long long, long long> >;

void pt1(const ReadVec &InputVector);
void pt2(const ReadVec &InputVector);
std::vector<std::string> splitStringStream(const std::string &s,
                                           char delimiter);

int main() {
  ReadVec InputVector;
  std::ifstream inputFile("./input.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }
  std::string line;
  while (std::getline(inputFile, line)) {
    std::vector<std::string> res = splitStringStream(line, ',');
    std::pair<long long, long long> p = std::make_pair(stoll(res[0]), stoll(res[1]));
    InputVector.push_back(p);
  }
  pt1(InputVector);
  // pt2(InputVector);
}

void pt1(const ReadVec &InputVector) {
    long long largestArea = 0;
    for (size_t i = 0; i < InputVector.size(); i++) {
        for (size_t j = i + 1; j < InputVector.size(); j++) {
            long long w = abs(InputVector[i].first - InputVector[j].first + 1);
            long long h = abs(InputVector[i].second - InputVector[j].second + 1);
            long long area = w * h;
            if (largestArea < area) {
                largestArea = area;
                // std::cout << InputVector[i].first << "," << InputVector[i].second << std::endl;
                // std::cout << InputVector[j].first << "," << InputVector[j].second << std::endl;
                // std::cout << i << " " << j << " " << area << std::endl;
            }
        }
    }
    std::cout << largestArea << std::endl;
}

void pt2(const ReadVec &InputVector);

std::vector<std::string> splitStringStream(const std::string &s,
                                           char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::stringstream ss(s);
  while (std::getline(ss, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}
