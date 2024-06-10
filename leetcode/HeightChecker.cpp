// Authored by Jie Huang
// 6/10/24
// 1051. Height Checker

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class HeightChecker {
  public:
    int heightChecker(vector<int> &heights) {
        vector<int> v(heights);
        sort(v.begin(), v.end());
        int count{0};
        for (int i = 0; i < heights.size(); ++i) {
            if (v[i] != heights[i]) {
                count++;
            }
        }
        return count;
    }
};

HeightChecker test;
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
    vector<int> v{1, 1, 4, 2, 1, 3};
    a.assertEquals(test.heightChecker(v), 3);
}

void testcase2() {
    vector<int> v{5, 1, 2, 3, 4};
    a.assertEquals(test.heightChecker(v), 5);
}

void testcase3() {
    vector<int> v{1, 2, 3, 4, 5};
    a.assertEquals(test.heightChecker(v), 0);
}