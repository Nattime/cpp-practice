// Authored by Jie Huang
// 6/3/24
// 2486. Append Characters to String to Make Subsequence

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class AppendCharactersToStringToMakeSubsequence {
  public:
    int appendCharacters(string s, string t) {
        int index = 0;
        int len = t.length();
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == t[index]) {
                if (++index == len) {
                    return 0;
                }
            }
        }
        return len - index;
    }
};

AppendCharactersToStringToMakeSubsequence test;
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
    a.assertEquals(test.appendCharacters("coaching", "coding"), 4);
}

void testcase2() {
    a.assertEquals(test.appendCharacters("abcde", "a"), 0);
}

void testcase3() {
    a.assertEquals(test.appendCharacters("z", "abcde"), 5);
}