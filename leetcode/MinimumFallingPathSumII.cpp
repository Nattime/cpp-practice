// Authored by Jie Huang
// 4/26/24
// 1289. Minimum Falling Path Sum II

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class MinimumFallingPathSumII {
  public:
    int minFallingPathSum(vector<vector<int>> &grid) {
        int sum{0};
        int prev{0};
        int index{-1};
        for (vector<int> row : grid) {
            int currSum{INT_MAX};
            int prevSum{INT_MAX};
            int currIndex{-1};
            for (int j = 0; j < row.size(); ++j) {
                int total{row[j]};
                if (j != index) {
                    total += sum;
                } else {
                    total += prev;
                }
                if (total < currSum) {
                    prevSum = currSum;
                    currSum = total;
                    currIndex = j;
                } else if (total < prevSum) {
                    prevSum = total;
                }
            }
            sum = currSum;
            prev = prevSum;
            index = currIndex;
        }
        return sum;
    }
};

MinimumFallingPathSumII test;
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
    vector<vector<int>> v{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    a.assertEquals(test.minFallingPathSum(v), 13);
}

void testcase2() {
    vector<vector<int>> v{{7}};
    a.assertEquals(test.minFallingPathSum(v), 7);
}

void testcase3() {
    vector<vector<int>> v{{-73, 61, 43, -48, -36}, {3, 30, 27, 57, 10}, {96, -76, 84, 59, -15}, {5, -49, 76, 31, -7}, {97, 91, 61, -46, 67}};
    a.assertEquals(test.minFallingPathSum(v), -192);
}