// Authored by Jie Huang
// 6/14/24
// 945. Minimum Increment to Make Array Unique

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class MinimumIncrementToMakeArrayUnique {
  public:
    int minIncrementForUnique(vector<int> &nums) {
        int ret = 0;
        int prevNum = 0;
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            ret += max(prevNum - num, 0);
            prevNum = max(num, prevNum) + 1;
        }
        return ret;
    }
};

MinimumIncrementToMakeArrayUnique test;
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
    vector<int> v{1, 2, 2};
    a.assertEquals(test.minIncrementForUnique(v), 1);
}

void testcase2() {
    vector<int> v{3, 2, 1, 2, 1, 7};
    a.assertEquals(test.minIncrementForUnique(v), 6);
}

void testcase3() {
}