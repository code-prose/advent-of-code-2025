#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::vector< std::vector<int> > input_vecs;
  std::ifstream inputFile("./input.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }
  std::string line;
  while (std::getline(inputFile, line)) {
    std::vector<int> temp;
    for (auto &i : line) {
      temp.push_back(i - '0');
    }
    input_vecs.push_back(temp);
  }
  inputFile.close();
  long long output = 0;
  int highest = 0;
  int second_highest = 0;
  size_t highest_idx = 0;

  for (auto &vec : input_vecs) {
    highest_idx = 0;
    highest = 0;
    second_highest = 0;

    for (size_t i = 0; i < vec.size() - 1; i++) {
      int t_highest = highest;
      highest = std::max(highest, vec[i]);
      if (highest != t_highest) {
        highest_idx = i + 1;
      }
    }
    for (size_t j = highest_idx; j < vec.size(); j++) {
      second_highest = std::max(second_highest, vec[j]);
    }
    int num = highest * 10 + second_highest;
    output += num;
  }
  std::cout << output << std::endl;
}
