// Authored by Jie Huang
// 5/3/24
// 165. Compare Version Numbers

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class CompareVersionNumbers {
  public:
    int compareVersion(string version1, string version2) {
        for (int i{0}, j{0}; i < version1.size() || j < version2.size(); i++, j++) {
            int v1 = 0, v2 = 0;
            while (i < version1.size() && version1[i] != '.') {
                v1 = v1 * 10 + (version1[i++] - '0');
            }
            while (j < version2.size() && version2[j] != '.') {
                v2 = v2 * 10 + (version2[j++] - '0');
            }
            if (v1 > v2) {
                return 1;
            } else if (v1 < v2) {
                return -1;
            }
        }
        return 0;
    }
};

CompareVersionNumbers test;
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
    a.assertEquals(test.compareVersion("1.01", "1.001"), 0);
}

void testcase2() {
    a.assertEquals(test.compareVersion("1.0", "1.0.0"), 0);
}

void testcase3() {
    a.assertEquals(test.compareVersion("0.1", "1.1"), -1);
}