// Authored by Jie Huang
// 3/13/24
// 2485. Find the Pivot Integer

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class FindThePivotInteger {
  public:
    int pivotInteger(int n) {
        int b{1};
        int bSum{0};
        int eSum{0};
        while (b < n) {
            if (bSum <= eSum) {
                bSum += b;
                b++;
            } else {
                eSum += n;
                n--;
            }
        }
        if (bSum == eSum) {
            return n;
        }
        return -1;
    }
};

FindThePivotInteger test;
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
    a.assertEquals(test.pivotInteger(8), 6);
}

void testcase2() {
    a.assertEquals(test.pivotInteger(1), 1);
}

void testcase3() {
    a.assertEquals(test.pivotInteger(4), -1);
}