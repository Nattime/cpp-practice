// Authored by Jie Huang
// 7/1/24
// 1550. Three Consecutive Odds

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class ThreeConsecutiveOdds {
  public:
    bool threeConsecutiveOdds(vector<int> &arr) {
        int count = 0;
        for (int iter : arr) {
            if (iter % 2 == 1) {
                count++;
            } else {
                count = 0;
            }
            if (count == 3) {
                return true;
            }
        }
        return false;
    }
};

ThreeConsecutiveOdds test;
Create c{};
Print p{};
Assert a{};

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    vector<int> v{2, 6, 4, 1};
    a.assertEquals(test.threeConsecutiveOdds(v), false);
}

void testcase2() {
    vector<int> v{1, 2, 34, 3, 4, 5, 7, 23, 12};
    a.assertEquals(test.threeConsecutiveOdds(v), true);
}

void testcase3() {
}