#include <deque>

class Dial {
    std::deque<int> dial;

public:
    Dial();
    void rotate_left(int amount);
    void rotate_right(int amount);
    int return_pos();
};
