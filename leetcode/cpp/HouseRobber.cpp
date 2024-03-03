// Authored by Jie Huang
// 1/25/24
// 198. House Robber

#include "cpp_header.h"

void testcase1();
void testcase2();

class HouseRobber {
  public:
    int rob(vector<int> &nums) {
        int p0{0};
        int p1{0};

        for (int i = 0; i < nums.size(); i++) {    
            int m = max(p0 + nums[i], p1);
            p0 = p1;
            p1 = m;
        }

        return p1;
    }
};

HouseRobber test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();

    return 0;
}

void testcase1() {
    vector<int> v{1, 2, 3, 1};
    cout << test.rob(v) << endl;
}

void testcase2() {
    vector<int> v{2, 7, 9, 3, 1};
    cout << test.rob(v) << endl;
}