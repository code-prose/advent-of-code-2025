#include <fstream>
#include <iostream>
#include <string>

std::vector<long long> splitString(const std::string &str, const std::string &delimiter) {
    std::vector<long long> values;
    size_t lastPos = 0;
    size_t nextPos = 0;
    while ((nextPos = str.find(delimiter, lastPos)) != std::string::npos) {
        values.push_back(stoll(str.substr(lastPos, nextPos - lastPos)));
        lastPos = nextPos + delimiter.length();
    }
    values.push_back(stoll(str.substr(lastPos)));
    return values;
}


int main() {
    std::vector<std::string> inputs;
    std::ifstream inputFile("./input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line, ',')) {
        inputs.push_back(line);
    }

    inputFile.close();
    long long silly = 0;
    for (auto &input : inputs) {
        std::vector<long long> range = splitString(input, "-");
        for (long long i = range.at(0); i <= range.at(1); i++) {
            std::string str = std::to_string(i);
            // Part 1: Check if the number is a pattern repeated exactly twice
            if (str.length() % 2 == 0) {
                size_t half = str.length() / 2;
                if (str.substr(0, half) == str.substr(half)) {
                    silly += i;
                }
            }
        }

    }
    std::cout << silly << std::endl;
}
