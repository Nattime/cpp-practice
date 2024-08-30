// Authored by Jie Huang
// 8/30/24
// 860. Lemonade Change

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

Create c{};
Print p{};
Assert a{};

class LemonadeChange {
  public:
    bool lemonadeChange(vector<int> &bills) {
        int five = 0;
        int ten = 0;
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five < 1) {
                    return false;
                }
                five--;
                ten++;
            } else {
                if (ten > 0 && five > 0) {
                    five--;
                    ten--;
                } else if (five > 2) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

LemonadeChange test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    vector<int> v{5, 5, 5, 10, 20};
    a.assertEquals(test.lemonadeChange(v), true);
}

void testcase2() {
    vector<int> v{5, 5, 10, 10, 20};
    a.assertEquals(test.lemonadeChange(v), false);
}

void testcase3() {
}