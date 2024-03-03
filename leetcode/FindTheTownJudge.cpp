// Authored by Jie Huang
// 2/22/24
// 997. Find the Town Judge

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class FindTheTownJudge {
  public:
    int findJudge(int n, vector<vector<int>> &trust) {
        vector<int> f(n, 0);
        vector<int> s(n, 0);
        for (auto iter : trust) {
            f[iter[0] - 1]++;
            s[iter[1] - 1]++;
        }
        for (int i = 0; i < n; i++) {
            if ((f[i] == 0) && (s[i] == (n - 1))) {
                return i + 1;
            }
        }
        return -1;
    }
};

FindTheTownJudge test;
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
    vector<vector<int>> trust{{1, 2}};
    a.assertEquals(test.findJudge(2, trust), 2);
}

void testcase2() {
    vector<vector<int>> trust{{1, 3}, {2, 3}};
    a.assertEquals(test.findJudge(3, trust), 3);
}

void testcase3() {
    vector<vector<int>> trust{{1, 3}, {2, 3}, {3, 1}};
    a.assertEquals(test.findJudge(3, trust), -1);
}