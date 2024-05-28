// Authored by Jie Huang
// 5/28/24
// 1208. Get Equal Substrings Within Budget

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class GetEqualSubstringsWithinBudget {
  public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        int start = 0;
        int diff = 0;
        int ret = 0;
        for (int iter = 0; iter < len; ++iter) {
            diff += abs(s[iter] - t[iter]);
            while (maxCost < diff) {
                diff -= abs(s[start] - t[start]);
                ++start;
            }
            ret = max(iter - start + 1, ret);
        }
        return ret;
    }
};

GetEqualSubstringsWithinBudget test;
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
    a.assertEquals(test.equalSubstring("abcd", "bcdf", 3), 3);
}

void testcase2() {
    a.assertEquals(test.equalSubstring("abcd", "cdef", 3), 1);
}

void testcase3() {
    a.assertEquals(test.equalSubstring("abcd", "acde", 0), 1);
}