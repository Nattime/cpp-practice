// Authored by Jie Huang
// 4/6/24
// 1249. Minimum Remove to Make Valid Parentheses

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class MinimumRemoveToMakeValidParentheses {
  public:
    string minRemoveToMakeValid(string s) {
        int len = s.length();
        char arr[len];
        stack<int> stack{};
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            arr[i] = ch;
            if (ch == '(') {
                stack.push(i);
            } else if (ch == ')' && !stack.empty()) {
                stack.pop();
            } else if (ch == ')') {
                arr[i] = ' ';
            }
        }
        while (!stack.empty()) {
            arr[stack.top()] = ' ';
            stack.pop();
        }
        string str{};
        for (int i = 0; i < s.length(); i++) {
            if (arr[i] != ' ') {
                str += arr[i];
            }
        }
        return str;
    }
};

MinimumRemoveToMakeValidParentheses test;
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
    a.assertEquals(test.minRemoveToMakeValid("lee(t(c)o)de)"), "lee(t(c)o)de");
}

void testcase2() {
    a.assertEquals(test.minRemoveToMakeValid("a)b(c)d"), "ab(c)d");
}

void testcase3() {
    a.assertEquals(test.minRemoveToMakeValid("))(("), "");
}