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
            bool isInvalid = false;

            // Try each possible pattern length
            for (size_t patternLen = 1; patternLen <= str.length() / 2; patternLen++) {
                // Check if string length is divisible by pattern length
                if (str.length() % patternLen == 0) {
                    std::string pattern = str.substr(0, patternLen);
                    bool matches = true;

                    // Check if the entire string is made of this pattern repeated
                    for (size_t pos = patternLen; pos < str.length(); pos += patternLen) {
                        if (str.substr(pos, patternLen) != pattern) {
                            matches = false;
                            break;
                        }
                    }

                    if (matches) {
                        isInvalid = true;
                        break;
                    }
                }
            }

            if (isInvalid) {
                silly += i;
            }
        }

    }
    std::cout << silly << std::endl;
}
