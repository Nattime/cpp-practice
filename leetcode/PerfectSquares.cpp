// Authored by Jie Huang
// 2/8/24
// 279. Perfect Squares

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class PerfectSquares {
  public:
    int numSquares(int n) {
        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }
        for (int x = 0; x * x <= n; x++) {
            int y = (int)sqrt(n - x * x);
            if (x * x + y * y == n) {
                if (x == 0 || y == 0) {
                    return 1;
                } else {
                    return 2;
                }
            }
        }
        return 3;
    }
};

PerfectSquares test;
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
    a.assertEquals(test.numSquares(12), 3);
}

void testcase2() {
    a.assertEquals(test.numSquares(13), 2);
}

void testcase3() {
}