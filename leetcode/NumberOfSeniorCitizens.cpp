// Authored by Jie Huang
// 8/1/24
// 2678. Number of Senior Citizens

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class NumberOfSeniorCitizens {
  public:
    int countSeniors(vector<string> &details) {
        int count = 0;
        for (string iter : details) {
            int age = stoi(iter.substr(11, 2));
            if (age > 60) {
                ++count;
            }
        }
        return count;
    }
};

NumberOfSeniorCitizens test;
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
    vector<string> v{"7868190130M7522", "5303914400F9211", "9273338290F4010"};
    a.assertEquals(test.countSeniors(v), 2);
}

void testcase2() {
    vector<string> v{"1313579440F2036", "2921522980M5644"};
    a.assertEquals(test.countSeniors(v), 0);
}

void testcase3() {
}