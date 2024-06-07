// Authored by Jie Huang
// 6/7/24
// 648. Replace Words

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class ReplaceWords {
  private:
    class Dict {
      public:
        Dict *children[26];
        string word;
    };
    void add(Dict *root, string str) {
        for (char c : str) {
            int i = c - 'a';
            if (root->children[i] == nullptr) {
                root->children[i] = new Dict();
            }
            root = root->children[i];
        }
        root->word = str;
    }
    string get(Dict *root, string str) {
        for (char c : str) {
            int i = c - 'a';
            if (root->word != "") {
                return root->word;
            }
            if (root->children[i] == nullptr) {
                return str;
            }
            root = root->children[i];
        }
        return str;
    }

  public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        Dict *root = new Dict();
        for (string s : dictionary) {
            add(root, s);
        }
        string str;
        string delimiter = " ";
        size_t pos = 0;
        string token;
        while ((pos = sentence.find(delimiter)) != string::npos) {
            token = sentence.substr(0, pos);
            str += " " + get(root, token);
            sentence.erase(0, pos + delimiter.length());
        }
        str += " " + get(root, sentence);
        return str.substr(1);
    }
};

ReplaceWords test;
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
    vector<string> input = {"cat", "bat", "rat"};
    a.assertEquals(test.replaceWords(input, "the cattle was rattled by the battery"), "the cat was rat by the bat");
}

void testcase2() {
    vector<string> input = {"a", "b", "c"};
    a.assertEquals(test.replaceWords(input, "aadsfasf absbs bbab cadsfafs"), "a a b c");
}

void testcase3() {
}