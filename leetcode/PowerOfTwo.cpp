// Authored by Jie Huang
// 2/19/24
// 231. Power of Two

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class PowerOfTwo {
  public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return (n & (n - 1)) == 0 ? true : false;
    }
};

PowerOfTwo test;
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
    a.assertTrue(test.isPowerOfTwo(1));
}

void testcase2() {
    a.assertTrue(test.isPowerOfTwo(16));
}

void testcase3() {
    a.assertEquals(test.isPowerOfTwo(3), false);
}