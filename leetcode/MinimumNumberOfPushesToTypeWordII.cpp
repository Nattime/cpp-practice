// Authored by Jie Huang
// 8/6/24
// 3016. Minimum Number of Pushes to Type Word II

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class MinimumNumberOfPushesToTypeWordII {
  public:
    int minimumPushes(string word) {
        vector<int> v(26, 0);
        int ret = 0;
        int len = word.size();
        for (int i = 0; i < len; ++i) {
            int in = word[i] - 'a';
            ++v[in];
        }
        sort(v.begin(), v.end());
        int div = 1;
        int c = 0;
        for (int i = 25; i >= 0; --i) {
            if (c == 8) {
                ++div;
                c = 0;
            }
            ret += v[i] * div;
            ++c;
        }
        return ret;
    }
};

MinimumNumberOfPushesToTypeWordII test;
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
    a.assertEquals(test.minimumPushes("abcde"), 5);
}

void testcase2() {
    a.assertEquals(test.minimumPushes("xyzxyzxyzxyz"), 12);
}

void testcase3() {
    a.assertEquals(test.minimumPushes("aabbccddeeffgghhiiiiii"), 24);
}