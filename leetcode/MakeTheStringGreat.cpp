// Authored by Jie Huang
// 8/28/24
// 1544. Make The String Great

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

Create c{};
Print p{};
Assert a{};

class MakeTheStringGreat {
  public:
    string makeGood(string s) {
        int len = s.size();
        char arr[len];
        int beg = 0;
        int trav = 0;
        for (int i = 0; i < len; ++i) {
            arr[i] = s[i];
        }
        while (trav < len) {
            if (beg > 0 && abs(arr[beg - 1] - arr[trav]) == 32) {
                beg--;
            } else {
                arr[beg] = arr[trav];
                beg++;
            }
            trav++;
        }
        string str;
        for (int i = 0; i < beg; ++i) {
            str += arr[i];
        }
        return str;
    }
};

MakeTheStringGreat test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    a.assertEquals(test.makeGood("leEeetcode"), "leetcode");
}

void testcase2() {
    a.assertEquals(test.makeGood("abBAcC"), "");
}

void testcase3() {
    a.assertEquals(test.makeGood("hKhHkHjgGJEiBbIe"), "");
}