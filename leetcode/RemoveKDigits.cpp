// Authored by Jie Huang
// 4/11/24
// 402. Remove K Digits

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class RemoveKDigits {
  public:
    string removeKdigits(string num, int k) {
        if (num.length() <= k) {
            return "0";
        }
        string str{};
        vector<char> stack{};
        for (int i = 0; i < num.length(); ++i) {
            while (k > 0 && !stack.empty() && (stack.back() > num[i])) {
                stack.pop_back();
                --k;
            }
            stack.push_back(num[i]);
        }
        while (k-- > 0) {
            stack.pop_back();
        }
        for (char c : stack) {
            if (c == '0' && str.empty()) {
                continue;
            }
            str += c;
        }
        return str.empty() ? "0" : str;
    }
};

RemoveKDigits test;
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
    a.assertEquals(test.removeKdigits("1432219", 3), "1219");
}

void testcase2() {
    a.assertEquals(test.removeKdigits("10200", 1), "200");
}

void testcase3() {
    a.assertEquals(test.removeKdigits("10", 2), "0");
}