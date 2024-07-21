// Authored by Jie Huang
// 7/20/24
// 1605. Find Valid Matrix Given Row and Column Sums

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class FindValidMatrixGivenRowAndColumnSums {
  public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
        int rLen = rowSum.size();
        int cLen = colSum.size();
        vector<vector<int>> ret(rLen, vector<int>(cLen, 0));
        for (int row = 0; row < rLen; row++) {
            for (int col = 0; col < cLen; col++) {
                ret[row][col] = min(rowSum[row], colSum[col]);
                rowSum[row] -= ret[row][col];
                colSum[col] -= ret[row][col];
            }
        }
        return ret;
    }
};

FindValidMatrixGivenRowAndColumnSums test;
Create c{};
Print p{};
Assert a{};

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

bool sumEquals(vector<vector<int>> &mat, vector<int> &rowSum, vector<int> &colSum) {
    int rLen = rowSum.size();
    int cLen = colSum.size();
    vector<int> r(rLen, 0);
    vector<int> c(cLen, 0);
    for (int row = 0; row < rLen; row++) {
        for (int col = 0; col < cLen; col++) {
            r[row] += mat[row][col];
            c[col] += mat[row][col];
        }
    }
    for (int i = 0; i < cLen; i++) {
        if (c[i] != colSum[i]) {
            return false;
        }
    }
    for (int i = 0; i < rLen; i++) {
        if (r[i] != rowSum[i]) {
            return false;
        }
    }
    return true;
}

void testcase1() {
    vector<int> rowSum = {3, 8};
    vector<int> colSum{4, 7};
    vector<vector<int>> output{{3, 0}, {1, 7}};
    a.assertEquals(test.restoreMatrix(rowSum, colSum), output);
}

void testcase2() {
    vector<int> rowSum{5, 7, 10};
    vector<int> colSum{8, 6, 8};
    vector<vector<int>> mat = test.restoreMatrix(rowSum, colSum);
    vector<int> r{5, 7, 10};
    vector<int> c{8, 6, 8};
    a.assertTrue(sumEquals(mat, r, c));
}

void testcase3() {
}