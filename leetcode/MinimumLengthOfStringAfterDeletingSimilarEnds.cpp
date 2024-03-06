// Authored by Jie Huang
// 3/5/24
// 1750 MinimumLengthOfStringAfterDeletingSimilarEnds

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class MinimumLengthOfStringAfterDeletingSimilarEnds {
  public:
    int minimumLength(string s) {
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end && s[begin] == s[end]) {
            char ch = s[begin];
            while (begin <= end && s[begin] == ch) {
                begin++;
            }
            while (end >= begin && s[end] == ch) {
                end--;
            }
        }
        return (end - begin) + 1;
    }
};

MinimumLengthOfStringAfterDeletingSimilarEnds test;
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
    a.assertEquals(test.minimumLength("ca"), 2);
}

void testcase2() {
    a.assertEquals(test.minimumLength("cabaabac"), 0);
}

void testcase3() {
    a.assertEquals(test.minimumLength("aabccabba"), 3);
}