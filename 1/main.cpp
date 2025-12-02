#include "utils/dial.h"
#include <iostream>
#include <stdio.h>
#include <print>
#include <fstream>
#include <string>

int main() {
    std::vector<std::string> input;
    std::ifstream inputFile("./input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        input.push_back(line);
    }

    inputFile.close();

    Dial dial;
    int count = 0;
    int pos;
    for (std::string line : input) {
        char direction = line[0];
        int distance = std::stoi(line.substr(1));

        if (direction == 'L') {
            dial.rotate_left(distance);
            pos = dial.return_pos();
        } else if (direction == 'R') {
            dial.rotate_right(distance);
            pos = dial.return_pos();
        }
        if (pos == 0) { count++; } 
    }

    std::cout << count << std::endl;

    return 0;
}
