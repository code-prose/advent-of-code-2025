#include "dial.h"


Dial::Dial() {
    for (int i = 0; i < 100; i++) {
        dial.push_back(i);
    }
}

int Dial::return_pos() {
    return dial[0];
}

void Dial::rotate_left(int amount) {
    for (int i = 0; i < amount; i++) {
        int val;
        val = dial.back();
        dial.pop_back();
        dial.push_front(val);
    }
}

void Dial::rotate_right(int amount) {
    for (int i = 0; i < amount; i++) {
        int val;
        val = dial.front();
        dial.pop_front();
        dial.push_back(val);
    }
}
