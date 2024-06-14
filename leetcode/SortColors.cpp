// Authored by Jie Huang
// 6/12/24
// 75. Sort Colors

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class SortColors {
  public:
    void sortColors(vector<int> &nums) {
        vector<int> v{0, 0, 0};
        for (int num : nums) {
            v[num]++;
        }
        int in = 0;
        for (int num = 0; num < v.size(); num++) {
            for (int i = 0; i < v[num]; i++) {
                nums[in++] = num;
            }
        }
    }
};

SortColors test;
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
    vector<int> input{2, 0, 2, 1, 1, 0};
    vector<int> output{0, 0, 1, 1, 2, 2};
    test.sortColors(input);
    a.assertEquals(input, output);
}

void testcase2() {
    vector<int> input{2, 0, 1};
    vector<int> output{0, 1, 2};
    test.sortColors(input);
    a.assertEquals(input, output);
}

void testcase3() {
}