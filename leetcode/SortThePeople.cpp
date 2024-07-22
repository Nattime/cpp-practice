// Authored by Jie Huang
// 7/22/24
// 2418. Sort the People

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class SortThePeople {
  public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        unordered_map<int, string> map{};
        int len = names.size();
        for (int i = 0; i < len; i++) {
            map.insert({heights[i], names[i]});
        }
        sort(heights.begin(), heights.end(), greater<int>());
        for (int i = 0; i < len; i++) {
            names[i] = map.find(heights[i])->second;
        }
        return names;
    }
};

SortThePeople test;
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
    vector<string> names{"Mary", "John", "Emma"};
    vector<int> heights{180, 165, 170};
    vector<string> expected{"Mary", "Emma", "John"};
    a.assertEquals(test.sortPeople(names, heights), expected);
}

void testcase2() {
    vector<string> names{"Alice", "Bob", "Bob"};
    vector<int> heights{155, 185, 150};
    vector<string> expected{"Bob", "Alice", "Bob"};
    a.assertEquals(test.sortPeople(names, heights), expected);
}

void testcase3() {
}