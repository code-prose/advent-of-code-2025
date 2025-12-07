#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>


using ReadVec = std::vector< std::vector<int> >;
void pt1();
void pt2();
std::vector<std::string> splitStringStream(const std::string& s, char delimiter);


int main() {
  ReadVec InputVector;
  std::ifstream inputFile("./test_input.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }
  std::string line;
  int i = 0;
  while (std::getline(inputFile, line)) {
        std::vector<int> temp;
        std::vector<std::string> results = splitStringStream(line, ' ');
        for (auto &res: results) {
            temp.push_back(stoi(res));
        }
        InputVector.push_back(temp);
  }
  // std::cout << InputVector << std::endl;
  // pt1();
  // pt2();

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

