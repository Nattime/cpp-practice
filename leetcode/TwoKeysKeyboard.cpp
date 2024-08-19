// Authored by Jie Huang
// 8/19/24
// 650. 2 Keys Keyboard

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

Create c{};
Print p{};
Assert a{};

class TwoKeysKeyboard {
  public:
    int minSteps(int n) {
        vector<int> smallPrime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int ret = 0;
        bool isPrime = true;
        do {
            isPrime = false;
            for (int i : smallPrime) {
                if (n % i == 0) {
                    ret += i;
                    n /= i;
                    isPrime = true;
                    break;
                }
            }
        } while (isPrime);
        return n == 1 ? ret : ret + n;
    }
};

TwoKeysKeyboard test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    a.assertEquals(test.minSteps(3), 3);
}

void testcase2() {
    a.assertEquals(test.minSteps(1), 0);
}

void testcase3() {
}