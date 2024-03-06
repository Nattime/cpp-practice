// Authored by Jie Huang
// 2/5/24
// 387. First Unique Character in a String

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class FirstUniqueCharacterInAString {
  public:
    int firstUniqChar(string s) {
        if (s.empty()) {
            return 0;
        }
        int arr[26]{};

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            int ind = (int)(ch - 'a');
            if (arr[ind] == 0) {
                arr[ind] = i;
            } else if (arr[ind] > 0) {
                arr[ind] = -i;
            }
        }

        int in = (s[0] - 'a');
        if (arr[in] == 0) {
            return 0;
        }
        int m = s.length() + 1;
        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0 && i != in) {
                m = min(m, arr[i]);
            }
        }
        return m == s.length() + 1 ? -1 : (arr[(s[0] - 'a')] == m ? -1 : m);
    }
};

FirstUniqueCharacterInAString test;
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
    string s = "leetcode";
    a.assertEquals(test.firstUniqChar(s), 0);
}

void testcase2() {
    string s = "loveleetcode";
    a.assertEquals(test.firstUniqChar(s), 2);
}

void testcase3() {
    string s = "aabb";
    a.assertEquals(test.firstUniqChar(s), -1);
}