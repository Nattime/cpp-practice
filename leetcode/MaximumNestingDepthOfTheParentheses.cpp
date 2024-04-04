// Authored by Jie Huang
// 4/4/24
// 1614. Maximum Nesting Depth of the Parentheses

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class MaximumNestingDepthOfTheParentheses {
  public:
    int maxDepth(string s) {
        int count{0};
        int ret{0};

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                ret = max(count, ret);
                count--;
            }
        }

        return ret;
    }
};

MaximumNestingDepthOfTheParentheses test;
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
    a.assertEquals(test.maxDepth("(1+(2*3)+((8)/4))+1"), 3);
}

void testcase2() {
    a.assertEquals(test.maxDepth("(1)+((2))+(((3)))"), 3);
}

void testcase3() {
}