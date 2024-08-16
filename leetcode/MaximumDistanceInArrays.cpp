// Authored by Jie Huang
// 8/16/24
// 624. Maximum Distance in Arrays

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

Create c{};
Print p{};
Assert a{};

class MaximumDistanceInArrays {
  public:
    int maxDistance(vector<vector<int>> &arrays) {
        int mini = arrays[0][0];
        int maxi = arrays[0][arrays[0].size() - 1];
        int ret = 0;
        for (int i = 1; i < arrays.size(); i++) {
            ret = max(ret, max(arrays[i][arrays[i].size() - 1] - mini, maxi - arrays[i][0]));
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i][arrays[i].size() - 1]);
        }
        return ret;
    }
};

MaximumDistanceInArrays test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    vector<vector<int>> v{{1, 2, 3}, {4, 5}, {1, 2, 3}};
    a.assertEquals(test.maxDistance(v), 4);
}

void testcase2() {
    vector<vector<int>> v{{1}, {1}};
    a.assertEquals(test.maxDistance(v), 0);
}

void testcase3() {
    vector<vector<int>> v{{-1, 0, 1}, {-1, 1}, {1, 2}};
    a.assertEquals(test.maxDistance(v), 3);
}