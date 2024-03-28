// Authored by Jie Huang
// 3/27/24
// 713. Subarray Product Less Than K

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class SubarrayProductLessThanK {
  public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int count = 0;
        int prod = 1;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            prod *= nums[i];
            while (prod >= k) {
                prod /= nums[j++];
            }
            count += (i - j) + 1;
        }
        return count;
    }
};

SubarrayProductLessThanK test;
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
    vector<int> v{10, 5, 2, 6};
    a.assertEquals(test.numSubarrayProductLessThanK(v, 100), 8);
}

void testcase2() {
    vector<int> v{1, 2, 3};
    a.assertEquals(test.numSubarrayProductLessThanK(v, 0), 0);
}

void testcase3() {
}