// Authored by Jie Huang
// 4/28/24
// 2997. Minimum Number of Operations to Make Array XOR Equal to K

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class MinimumNumberOfOperationsToMakeArrayXOREqualToK {
  public:
    int minOperations(vector<int> &nums, int k) {
        for (int iter : nums) {
            k ^= iter;
        }
        int count{0};
        while (k) {
            count += k & 1;
            k >>= 1;
        }
        return count;
    }
};

MinimumNumberOfOperationsToMakeArrayXOREqualToK test;
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
    vector<int> v{2, 1, 3, 4};
    a.assertEquals(test.minOperations(v, 1), 2);
}

void testcase2() {
    vector<int> v{2, 0, 2, 0};
    a.assertEquals(test.minOperations(v, 0), 0);
}

void testcase3() {
}