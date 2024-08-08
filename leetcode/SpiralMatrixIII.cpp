// Authored by Jie Huang
// 8/8/24
// 885. Spiral Matrix III

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class SpiralMatrixIII {
  public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int len = rows * cols;
        int turn = 0; // 0 right, 1 down, 2 left, 3 up
        int c = 1;
        int stepsLeft = 1;
        vector<vector<int>> mat(len);
        for (int i = 1; i <= len; ++i) {
            --stepsLeft;
            mat[i - 1] = vector<int>{rStart, cStart};
            if (turn == 0) {
                ++cStart;
            } else if (turn == 1) {
                ++rStart;
            } else if (turn == 2) {
                --cStart;
            } else {
                --rStart;
            }
            if (stepsLeft == 0) {
                turn = (turn + 1) % 4;
                if (turn == 0) {
                    ++c;
                } else if (turn == 2) {
                    ++c;
                }
                stepsLeft = c;
            }
            if (i + 1 <= len) {
                while (rStart < 0 || rStart >= rows || cStart < 0 || cStart >= cols) {
                    if (stepsLeft == 0) {
                        turn = (turn + 1) % 4;
                        if (turn == 0) {
                            ++c;
                        } else if (turn == 2) {
                            ++c;
                        }
                        stepsLeft = c;
                    }
                    if (turn == 0) {
                        ++cStart;
                    } else if (turn == 1) {
                        ++rStart;
                    } else if (turn == 2) {
                        --cStart;
                    } else {
                        --rStart;
                    }
                    --stepsLeft;
                }
            }
        }
        return mat;
    }
};

SpiralMatrixIII test;
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
    vector<vector<int>> v{{0, 0}, {0, 1}, {0, 2}, {0, 3}};
    a.assertEquals(test.spiralMatrixIII(1, 4, 0, 0), v);
}

void testcase2() {
    vector<vector<int>> v{{1, 4}, {1, 5}, {2, 5}, {2, 4}, {2, 3}, {1, 3}, {0, 3}, {0, 4}, {0, 5}, {3, 5}, {3, 4}, {3, 3}, {3, 2}, {2, 2}, {1, 2}, {0, 2}, {4, 5}, {4, 4}, {4, 3}, {4, 2}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}};
    a.assertEquals(test.spiralMatrixIII(5, 6, 1, 4), v);
}

void testcase3() {
}