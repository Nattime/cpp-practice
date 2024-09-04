// Authored by Jie Huang
// 9/4/24
// 1945. Sum of Digits of String After Convert

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

Create c{};
Print p{};
Assert a{};

class SumOfDigitsOfStringAfterConvert {
  public:
    int getLucky(string s, int k) {
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            int num = s[i] - 'a' + 1;
            while (num > 0) {
                ret += num % 10;
                num /= 10;
            }
        }
        for (int i = 1; i < k; ++i) {
            int temp = 0;
            while (ret > 0) {
                temp += ret % 10;
                ret /= 10;
            }
            ret = temp;
        }
        return ret;
    }
};

SumOfDigitsOfStringAfterConvert test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    a.assertEquals(test.getLucky("iiii", 1), 36);
}

void testcase2() {
    a.assertEquals(test.getLucky("leetcode", 2), 6);
}

void testcase3() {
    a.assertEquals(test.getLucky("zbax", 2), 8);
}