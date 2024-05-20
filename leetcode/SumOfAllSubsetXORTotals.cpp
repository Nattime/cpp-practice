// Authored by Jie Huang
// 5/20/24
// 1863. Sum of All Subset XOR Totals

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class SumOfAllSubsetXORTotals {
  public:
    int subsetXORSum(vector<int> &nums) {
        int sum = 0;
        for (int iter : nums) {
            sum |= iter;
        }
        return sum << (nums.size() - 1);
    }
};

SumOfAllSubsetXORTotals test;
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
    a.assertEquals(test.subsetXORSum(v), 6);
}

void testcase2() {
    vector<int> v{5, 1, 6};
    a.assertEquals(test.subsetXORSum(v), 28);
}

void testcase3() {
    vector<int> v{3, 4, 5, 6, 7, 8};
    a.assertEquals(test.subsetXORSum(v), 480);
}