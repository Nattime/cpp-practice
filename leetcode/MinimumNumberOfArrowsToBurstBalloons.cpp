// Authored by Jie Huang
// 3/18/24
// 452. Minimum Number of Arrows to Burst Balloons

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class MinimumNumberOfArrowsToBurstBalloons {
  public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) -> bool { return a[1] < b[1]; });
        int ret{1};
        int arr{points[0][1]};
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > arr) {
                arr = points[i][1];
                ret++;
            }
        }
        return ret;
    }
};

MinimumNumberOfArrowsToBurstBalloons test;
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
    vector<vector<int>> v{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    a.assertEquals(test.findMinArrowShots(v), 2);
}

void testcase2() {
    vector<vector<int>> v{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    a.assertEquals(test.findMinArrowShots(v), 4);
}

void testcase3() {
    vector<vector<int>> v{{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    a.assertEquals(test.findMinArrowShots(v), 2);
}