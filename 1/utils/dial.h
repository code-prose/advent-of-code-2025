#include <deque>

class Dial {
    std::deque<int> dial;
    int count;

public:
    Dial();
    void rotateLeftp1(int amount);
    void rotateLeftp2(int amount);
    void rotateRightp1(int amount);
    void rotateRightp2(int amount);
    int returnPos();
    int returnCount();
    void increment(int incr);
};
