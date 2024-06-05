// Authored by Jie Huang
// 6/5/24
// 1002. Find Common Characters

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class FindCommonCharacters {
  public:
    vector<string> commonChars(vector<string> &words) {
        vector<int> letterCount(26, 0);
        string w = words[0];
        for (int i = 0; i < w.length(); i++) {
            int ind = w[i] - 'a';
            letterCount[ind]++;
        }

        for (string word : words) {
            vector<int> count(26, 0);
            for (int i = 0; i < word.length(); i++) {
                int ind = word[i] - 'a';
                count[ind]++;
            }
            for (int i = 0; i < 26; i++) {
                letterCount[i] = min(count[i], letterCount[i]);
            }
        }

        vector<string> ret{};
        for (int i = 0; i < 26; i++) {
            if (letterCount[i] > 0) {
                for (int j = 0; j < letterCount[i]; j++) {
                    ret.push_back(string(1, i + 'a'));
                }
            }
        }
        return ret;
    }
};

FindCommonCharacters test;
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
    vector<string> input = {"bella", "label", "roller"};
    vector<string> output = {"e", "l", "l"};
    a.assertEquals(test.commonChars(input), output);
}

void testcase2() {
    vector<string> input = {"cool", "lock", "cook"};
    vector<string> output = {"c", "o"};
    a.assertEquals(test.commonChars(input), output);
}

void testcase3() {
}