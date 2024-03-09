// Authored by Jie Huang
// 3/8/24
// 3005. Count Elements With Maximum Frequency

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class CountElementsWithMaximumFrequency {
  public:
    int maxFrequencyElements(vector<int> &nums) {
        vector<int> v(101);
        int max = 0;
        int ret{0};
        for (int iter : nums) {
            int count = ++v[iter];
            if (count > max) {
                max = count;
                ret = 1;
            } else if (count == max) {
                ret++;
            }
        }
        return ret * max;
    }
};

CountElementsWithMaximumFrequency test;
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
    vector<int> v{1, 2, 2, 3, 1, 4};
    a.assertEquals(test.maxFrequencyElements(v), 4);
}

void testcase2() {
    vector<int> v{1, 2, 3, 4, 5};
    a.assertEquals(test.maxFrequencyElements(v), 5);
}

void testcase3() {
}