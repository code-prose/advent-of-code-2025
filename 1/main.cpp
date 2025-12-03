#include "utils/dial.h"
#include <iostream>
#include <stdio.h>
#include <print>
#include <fstream>
#include <string>


void p1(std::vector<std::string> &input) {
    Dial dial;
    int count = 0;
    int pos = 0;
    for (std::string line : input) {
        char direction = line[0];
        int distance = std::stoi(line.substr(1));

        if (direction == 'L') {
            dial.rotateLeftp1(distance);
            pos = dial.returnPos();
        } else if (direction == 'R') {
            dial.rotateRightp1(distance);
            pos = dial.returnPos();
        }
        if (pos == 0) { count++; }
    }

    std::cout << count << std::endl;
}

void p2(std::vector<std::string> &input) {
    Dial dial;
    for (std::string line : input) {
        char direction = line[0];
        int distance = std::stoi(line.substr(1));

        if (direction == 'L') {
            dial.rotateLeftp2(distance);
        } else if (direction == 'R') {
            dial.rotateRightp2(distance);
        }
    }
    std::cout << dial.returnCount() << std::endl;
}

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

    p1(input);
    p2(input);

    return 0;
}
