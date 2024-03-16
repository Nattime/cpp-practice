// Authored by Jie Huang
// 3/16/24
// 525. Contiguous Array

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class ContiguousArray {
  public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> map{};
        map.insert({0, -1});
        int sum{0};
        int dis{0};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                sum += 1;
            } else {
                sum -= 1;
            }
            auto in = map.find(sum);
            if (in != map.end()) {
                dis = max(dis, i - in->second);
            } else {
                map.insert({sum, i});
            }
        }
        return dis;
    }
};

ContiguousArray test;
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
    vector<int> v{0, 1};
    a.assertEquals(test.findMaxLength(v), 2);
}

void testcase2() {
    vector<int> v{0, 1, 0};
    a.assertEquals(test.findMaxLength(v), 2);
}

void testcase3() {
}