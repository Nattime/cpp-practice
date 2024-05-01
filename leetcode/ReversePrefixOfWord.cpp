// Authored by Jie Huang
// 4/30/24
// 2000. Reverse Prefix of Word

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class ReversePrefixOfWord {
  public:
    string reversePrefix(string word, char ch) {
        int index = word.find_first_of(ch) + 1;
        reverse(word.begin(), word.begin() + index);
        return word;
    }
};

ReversePrefixOfWord test;
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
    a.assertEquals(test.reversePrefix("abcdefd", 'd'), "dcbaefd");
}

void testcase2() {
    a.assertEquals(test.reversePrefix("xyxzxe", 'z'), "zxyxxe");
}

void testcase3() {
    a.assertEquals(test.reversePrefix("abcd", 'z'), "abcd");
}