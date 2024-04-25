// Authored by Jie Huang
// 4/24/24
// 1137. N-th Tribonacci Number

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class NthTribonacciNumber {
  public:
    int tribonacci(int n) {
        if (n < 2) {
            return n;
        } else if (n == 2) {
            return 1;
        }
        vector<int> arr{0, 1, 1};
        int temp{};
        int index = 0;
        for (int i = 2; i < n; i++) {
            temp = arr[2] + arr[1] + arr[0];
            arr[index++] = temp;
            index %= 3;
        }
        return temp;
    }
};

NthTribonacciNumber test;
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
    a.assertEquals(test.tribonacci(4), 4);
}

void testcase2() {
    a.assertEquals(test.tribonacci(25), 1389537);
}

void testcase3() {
    a.assertEquals(test.tribonacci(37), 2082876103);
}