#include "dial.h"


Dial::Dial() {
    for (int i = 50; i < 100; i++) {
        dial.push_back(i);
    }
    for (int i = 0; i < 50; i++) {
        dial.push_back(i);
    }
    count = 0;
}

void Dial::increment(int incr) {
    count += incr;
}

int Dial::returnCount() {
    return count;
}

int Dial::returnPos() {
    return dial[0];
}

void Dial::rotateLeftp1(int amount) {
    for (int i = 0; i < amount; i++) {
        int val;
        val = dial.back();
        dial.pop_back();
        dial.push_front(val);
    }
}

void Dial::rotateLeftp2(int amount) {
    for (int i = 0; i < amount; i++) {
        int val;
        val = dial.back();
        dial.pop_back();
        if (val == 0) {
            increment(1);
        }
        dial.push_front(val);
    }
}

void Dial::rotateRightp1(int amount) {
    for (int i = 0; i < amount; i++) {
        int val;
        val = dial.front();
        dial.pop_front();
        dial.push_back(val);
    }
}

void Dial::rotateRightp2(int amount) {
    for (int i = 0; i < amount; i++) {
        int val;
        val = dial.front();
        dial.pop_front();
        if (val == 0) {
            increment(1);
        }
        dial.push_back(val);
    }
}
