// Authored by Jie Huang
// 6/16/24
// 330. Patching Array

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class PatchingArray {
  public:
    int minPatches(vector<int> &nums, int n) {
        int ret = 0;
        int i = 0;
        long m = 1;
        while (m <= n) {
            if (i < nums.size() && nums[i] <= m) {
                m += nums[i++];
            } else {
                m += m;
                ret++;
            }
        }
        return ret;
    }
};

PatchingArray test;
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
    vector<int> v{1, 3};
    a.assertEquals(test.minPatches(v, 6), 1);
}

void testcase2() {
    vector<int> v{1, 5, 10};
    a.assertEquals(test.minPatches(v, 20), 2);
}

void testcase3() {
    vector<int> v{1, 2, 2};
    a.assertEquals(test.minPatches(v, 5), 0);
}