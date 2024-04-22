// Authored by Jie Huang
// 4/22/24
// 752. Open the Lock

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class OpenTheLock {
  private:
    vector<string> turnPin(string &str) {
        vector<string> res{};
        for (int i = 0; i < 4; ++i) {
            char c = str[i];
            str[i] = c == '0' ? '9' : (char)(c - 1);
            res.push_back(str);
            str[i] = c == '9' ? '0' : (char)(c + 1);
            res.push_back(str);
            str[i] = c;
        }
        return res;
    }

  public:
    int openLock(vector<string> &deadends, string target) {
        if (target == "0000") {
            return 0;
        }
        unordered_set<string> set(deadends.begin(), deadends.end());
        if (set.count("0000")) {
            return -1;
        }
        queue<string> queue{{"0000"}};
        set.insert("0000");
        int ans = 0;
        while (!queue.empty()) {
            ++ans;
            for (int n = queue.size(); n > 0; --n) {
                string str = queue.front();
                queue.pop();
                for (string iter : turnPin(str)) {
                    if (target == iter) {
                        return ans;
                    }
                    if (!set.count(iter)) {
                        queue.push(iter);
                        set.insert(iter);
                    }
                }
            }
        }
        return -1;
    }
};

OpenTheLock test;
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
    vector<string> v{"0201", "0101", "0102", "1212", "2002"};
    a.assertEquals(test.openLock(v, "0202"), 6);
}

void testcase2() {
    vector<string> v{"8888"};
    a.assertEquals(test.openLock(v, "0009"), 1);
}

void testcase3() {
    vector<string> v{"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    a.assertEquals(test.openLock(v, "8888"), -1);
}