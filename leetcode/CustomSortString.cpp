// Authored by Jie Huang
// 3/11/24
// 791. Custom Sort String

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class CustomSortString {
  public:
    int findInd(char c, string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == c) {
                return i;
            }
        }
        return -1;
    }
    string customSortString(string order, string s) {
        int len = order.length();
        vector<int> v(len);
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            int ind = findInd(c, order);
            if (ind != -1) {
                s[i] = '0';
                v[ind]++;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '0') {
                for (int in = 0; in < len; in++) {
                    if (v[in] > 0) {
                        s[i] = order[in];
                        v[in]--;
                        break;
                    }
                }
            }
        }

        return s;
    }
};

CustomSortString test;
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
    a.assertEquals(test.customSortString("cba", "abcd"), "cbad");
}

void testcase2() {
    a.assertEquals(test.customSortString("bcafg", "abcd"), "bcad");
}

void testcase3() {
    a.assertEquals(test.customSortString("kqep", "pekeqkkp"), "kkkqeepp");
}