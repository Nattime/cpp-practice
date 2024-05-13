// Authored by Jie Huang
// 5/13/24
// 861. Score After Flipping Matrix

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class ScoreAfterFlippingMatrix {
  public:
    int matrixScore(vector<vector<int>> &grid) {
        int len = grid.size();
        int colLen = grid[0].size();
        vector<int> colCount(colLen, 0);
        // flip row starting with 0
        for (int row = 0; row < len; row++) {
            int val = grid[row][0];
            if (val == 0) {
                for (int col = 0; col < colLen; col++) {
                    if (grid[row][col] == 1) {
                        grid[row][col] = 0;
                    } else {
                        grid[row][col] = 1;
                    }
                }
            }
        }
        // count number of 0 and 1 in columns
        for (int row = 0; row < len; row++) {
            for (int col = 0; col < colLen; col++) {
                int val = grid[row][col];
                if (val == 0) {
                    colCount[col]++;
                } else {
                    colCount[col]--;
                }
            }
        }
        // flip col if number of 0s > 1s
        for (int i = 0; i < colLen; i++) {
            if (colCount[i] > 0) {
                for (int row = 0; row < len; row++) {
                    grid[row][i] ^= 1;
                }
            }
        }
        int ret = 0;
        for (int row = 0; row < len; row++) {
            int num = grid[row][0];
            for (int col = 1; col < colLen; col++) {
                num = num * 2 + grid[row][col];
            }
            ret += num;
        }
        return ret;
    }
};

ScoreAfterFlippingMatrix test;
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
    vector<vector<int>> v{{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    a.assertEquals(test.matrixScore(v), 39);
}

void testcase2() {
    vector<vector<int>> v{{0, 1, 0, 0}, {0, 1, 1, 0}, {1, 1, 1, 0}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 1, 1, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {1, 1, 1, 0}};
    a.assertEquals(test.matrixScore(v), 113);
}

void testcase3() {
    vector<vector<int>> v{{0}};
    a.assertEquals(test.matrixScore(v), 1);
}