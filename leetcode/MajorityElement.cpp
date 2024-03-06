// Authored by Jie Huang
// 2/12/24
// 169. Majority Element

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class MajorityElement {
  public:
    int majorityElement(vector<int> &nums) {
        int count{0};
        int num{0};

        for (int iter : nums) {
            if (count == 0) {
                count = 1;
                num = iter;
            } else if (num == iter) {
                count++;
            } else {
                count--;
            }
        }

        return num;
    }
};

MajorityElement test;
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
    vector<int> nums{3, 2, 3};
    a.assertEquals(test.majorityElement(nums), 3);
}

void testcase2() {
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    a.assertEquals(test.majorityElement(nums), 2);
}

void testcase3() {
}