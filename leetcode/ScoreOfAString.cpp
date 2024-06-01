// Authored by Jie Huang
// 6/1/24
// 3110. Score of a String

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class ScoreOfAString {
  public:
    int scoreOfString(string s) {
        int sum = 0;
        for (int i = 1; i < s.length(); ++i) {
            sum += abs((s[i] - s[i - 1]));
        }
        return sum;
    }
};

ScoreOfAString test;
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
    a.assertEquals(test.scoreOfString("hello"), 13);
}

void testcase2() {
    a.assertEquals(test.scoreOfString("zaz"), 50);
}

void testcase3() {
}