// Authored by Jie Huang
// 7/29/24
// 1395. Count Number of Teams

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class CountNumberOfTeams {
  public:
    int numTeams(vector<int> &rating) {
        int ret = 0;
        int len = rating.size();
        for (int i = 1; i < len - 1; ++i) {
            int r[2] = {0};
            int l[2] = {0};
            int num = rating[i];
            for (int j = 0; j < i; ++j) {
                l[rating[j] < num]++;
            }
            for (int j = i + 1; j < len; ++j) {
                r[rating[j] > num]++;
            }
            ret += (r[0] * l[0]) + (r[1] * l[1]);
        }
        return ret;
    }
};

CountNumberOfTeams test;
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
    vector<int> v{2, 5, 3, 4, 1};
    a.assertEquals(test.numTeams(v), 3);
}

void testcase2() {
    vector<int> v{2, 1, 3};
    a.assertEquals(test.numTeams(v), 0);
}

void testcase3() {
    vector<int> v{1, 2, 3, 4};
    a.assertEquals(test.numTeams(v), 4);
}