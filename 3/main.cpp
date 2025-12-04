#include <fstream>
#include <iostream>
#include <string>



int main() {
    std::vector<std::vector<int>> input_vecs;
    std::ifstream inputFile("./input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<int> temp;
        for (auto &i : line) {
            temp.push_back((int)i);
        }
        input_vecs.push_back(temp);
    }
    inputFile.close();
    long long output = 0;
    int highest = 0;
    int second_highest = 0;
    for (auto &vec : input_vecs) {
        for (size_t i = 0; i < vec.size(); i++) {
            int t_highest = highest;
            highest = std::max(highest, vec[i]);
            if (highest != t_highest) {
                second_highest = 0;
            } else {
                second_highest = std::max(second_highest, vec[i]);
            }
        }
        int num = highest * 10 + second_highest;
        output += num;
    }
    std::cout << output << std::endl;
}
