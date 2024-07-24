// Authored by Jie Huang
// 7/24/24
// 2191. Sort the Jumbled Numbers

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class SortTheJumbledNumbers {
  public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
        vector<vector<int>> mat(nums.size(), vector<int>(3, 0));
        for (int i = 0; i < nums.size(); i++) {
            int n = 0;
            if (nums[i] == 0) {
                n = mapping[0];
            } else {
                int dec = 1;
                int temp = nums[i];
                while (temp > 0) {
                    int d = temp % 10;
                    n += (mapping[d] * dec);
                    temp /= 10;
                    dec *= 10;
                }
            }
            mat[i][0] = n;
            mat[i][1] = i;
            mat[i][2] = nums[i];
        }
        sort(mat.begin(), mat.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                return a[1] < b[1];
            }
        });
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = mat[i][2];
        }
        return nums;
    }
};

SortTheJumbledNumbers test;
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
    vector<int> mapping{8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
    vector<int> nums{991, 338, 38};
    vector<int> expected{338, 38, 991};
    a.assertEquals(test.sortJumbled(mapping, nums), expected);
}

void testcase2() {
    vector<int> mapping{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> nums{789, 456, 123};
    vector<int> expected{123, 456, 789};
    a.assertEquals(test.sortJumbled(mapping, nums), expected);
}

void testcase3() {
}