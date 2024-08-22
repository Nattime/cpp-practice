// Authored by Jie Huang
// 8/21/24
// 476. Number Complement

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

Create c{};
Print p{};
Assert a{};

class NumberComplement {
  public:
    int findComplement(int num) {
        if (num == 0) {
            return 1;
        }
        unsigned int len = 1 << (int)(log2(num));
        unsigned int bit = (len * 2) - 1;
        return num ^ bit;
    }
};

NumberComplement test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    a.assertEquals(test.findComplement(5), 2);
}

void testcase2() {
    a.assertEquals(test.findComplement(1), 0);
}

void testcase3() {
}