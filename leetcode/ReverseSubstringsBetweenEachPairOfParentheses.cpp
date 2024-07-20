// Authored by Jie Huang
// 7/20/24
// 1190. Reverse Substrings Between Each Pair of Parentheses

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class ReverseSubstringsBetweenEachPairOfParentheses {
  public:
    string reverseParentheses(string s) {
        string ret;
        stack<int> stack;
        unordered_map<int, int> map;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stack.push(i);
            } else if (s[i] == ')') {
                int j = stack.top();
                stack.pop();
                map[i] = j;
                map[j] = i;
            }
        }
        for (int i = 0, j = 1; i < s.length(); i += j) {
            if (s[i] == '(' || s[i] == ')') {
                i = map[i];
                j = -j;
            } else {
                ret += s[i];
            }
        }
        return ret;
    }
};

ReverseSubstringsBetweenEachPairOfParentheses test;
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
    a.assertEquals(test.reverseParentheses("(abcd)"), "dcba");
}

void testcase2() {
    a.assertEquals(test.reverseParentheses("(u(love)i)"), "iloveu");
}

void testcase3() {
    a.assertEquals(test.reverseParentheses("(ed(et(oc))el)"), "leetcode");
}