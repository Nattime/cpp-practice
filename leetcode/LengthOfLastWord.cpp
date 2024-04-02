// Authored by Jie Huang
// 4/1/24
// 58. Length of Last Word

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class LengthOfLastWord {
  public:
    int lengthOfLastWord(string s) {
        int start = s.length() - 1;
        while (s[start] == ' ') {
            start--;
        }
        for (int i = start; i >= 0; i--) {
            if (s[i] == ' ') {
                return start - i;
            }
        }
        return start + 1;
    }
};

LengthOfLastWord test;
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
    a.assertEquals(test.lengthOfLastWord("Hello World"), 5);
}

void testcase2() {
    a.assertEquals(test.lengthOfLastWord("   fly me   to   the moon  "), 4);
}

void testcase3() {
    a.assertEquals(test.lengthOfLastWord("luffy is still joyboy"), 6);
}