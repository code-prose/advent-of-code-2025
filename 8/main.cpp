#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
#include <set>
#include <map>


using ReadVec = std::vector<std::tuple<int, int, int>>;
std::vector<std::string> splitStringStream(const std::string& s, char delimiter);


class CustomSort {
    Operater<
}

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
        std::tuple<int, int, int> tup = std::make_tuple<int, int, int>(stoi(res[0]), stoi(res[1]), stoi(res[2]));
        std::cout << std::get<0>(tup) << " " << std::get<1>(tup) << " " << std::get<2>(tup) << std::endl;
        InputVector.push_back(tup);
  }
}

void pt1(ReadVec InputVector);


void pt2(ReadVec InputVector);

std::vector<std::string> splitStringStream(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(s);
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
