// Authored by Jie Huang
// 4/18/24
// 463. Island Perimeter

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class IslandPerimeter {
  public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int count{0};
        for (int row{0}; row < grid.size(); row++) {
            for (int col{0}; col < grid[row].size(); col++) {
                if (grid[row][col] == 1) {
                    count += 4;
                    if (row > 0 && grid[row - 1][col] == 1) {
                        count -= 2;
                    }
                    if (col > 0 && grid[row][col - 1] == 1) {
                        count -= 2;
                    }
                }
            }
        }
        return count;
    }
};

IslandPerimeter test;
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
    vector<vector<int>> grid{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    a.assertEquals(test.islandPerimeter(grid), 16);
}

void testcase2() {
    vector<vector<int>> grid{{1}};
    a.assertEquals(test.islandPerimeter(grid), 4);
}

void testcase3() {
    vector<vector<int>> grid{{1, 0}};
    a.assertEquals(test.islandPerimeter(grid), 4);
}