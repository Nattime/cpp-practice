// Authored by Jie Huang
// 7/26/24
// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class FindTheCityWithTheSmallestNumberOfNeighborsAtAThresholdDistance {
  public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        vector<vector<int>> v(n, vector<int>(n, distanceThreshold + 1));
        int ret = -1;
        int minCities = n;
        for (int i = 0; i < n; i++) {
            v[i][i] = 0;
        }
        for (auto iter : edges) {
            int i = iter[0];
            int j = iter[1];
            int w = iter[2];
            v[i][j] = w;
            v[j][i] = w;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (v[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            if (count <= minCities) {
                ret = i;
                minCities = count;
            }
        }
        return ret;
    }
};

FindTheCityWithTheSmallestNumberOfNeighborsAtAThresholdDistance test;
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
    vector<vector<int>> edges{{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    a.assertEquals(test.findTheCity(4, edges, 4), 3);
}

void testcase2() {
    vector<vector<int>> edges{{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    a.assertEquals(test.findTheCity(5, edges, 2), 0);
}

void testcase3() {
}