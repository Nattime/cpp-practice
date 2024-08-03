// Authored by Jie Huang
// 8/3/24
// 1460. Make Two Arrays Equal by Reversing Subarrays

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class MakeTwoArraysEqualByReversingSubarrays {
  public:
    bool canBeEqual(vector<int> &target, vector<int> &arr) {
        vector<int> v(1001, 0);
        for (int i = 0; i < target.size(); ++i) {
            ++v[target[i]];
            --v[arr[i]];
        }
        for (auto iter : v) {
            if (iter != 0) {
                return false;
            }
        }
        return true;
    }
};

MakeTwoArraysEqualByReversingSubarrays test;
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
    vector<int> target{1, 2, 3, 4};
    vector<int> arr{2, 4, 1, 3};
    a.assertEquals(test.canBeEqual(target, arr), true);
}

void testcase2() {
    vector<int> target{7};
    vector<int> arr{7};
    a.assertEquals(test.canBeEqual(target, arr), true);
}

void testcase3() {
    vector<int> target{3, 7, 9};
    vector<int> arr{3, 7, 11};
    a.assertEquals(test.canBeEqual(target, arr), false);
}