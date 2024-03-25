// Authored by Jie Huang
// 3/25/24
// 442. Find All Duplicates in an Array

#include "../resources/cpp_header.h"

Print p{};

void testcase1();
void testcase2();
void testcase3();

class FindAllDuplicatesInAnArray {
  public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> ret{};

        for (int iter : nums) {
            int num = (iter < 0 ? iter * -1 : iter) - 1;
            if (nums[num] >= 0) {
                nums[num] *= -1;
            } else {
                ret.push_back((num + 1));
            }
        }

        return ret;
    }
};

FindAllDuplicatesInAnArray test;
Create c{};

Assert a{};

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    vector<int> v{4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> output{2, 3};
    a.assertEquals(test.findDuplicates(v), output);
}

void testcase2() {
    vector<int> v{1, 1, 2};
    vector<int> output{1};
    a.assertEquals(test.findDuplicates(v), output);
}

void testcase3() {
    vector<int> v{1};
    vector<int> output{};
    a.assertEquals(test.findDuplicates(v), output);
}