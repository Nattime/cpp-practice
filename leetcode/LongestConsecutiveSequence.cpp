// Authored by Jie Huang
// 2/1/24
// 128. Longest Consecutive Sequence

#include "cpp_header.h"
#include <math.h>
#include <unordered_map>

using std::max;
using std::unordered_map;

void testcase1();
void testcase2();
void testcase3();

struct Pair {
    int start;
    int end;
};

class LongestConsecutiveSequence {
  public:
    int longestConsecutive(vector<int> &nums) {
        int m{0};
        unordered_map<int, Pair> map{};
        for (int iter : nums) {
            int diff{1};
            if (map.find(iter) == map.end()) {
                int begin = iter;
                int end = iter;
                auto indexEnd = map.find(iter + 1);
                if (indexEnd != map.end()) {
                    end = indexEnd->second.end;
                }
                auto indexBegin = map.find(iter - 1);
                if (indexBegin != map.end()) {
                    begin = indexBegin->second.start;
                }
                Pair p;
                p.start = begin;
                p.end = end;
                if (begin != iter && end != iter) { // update both start and end
                    auto st = map.find(end);
                    st->second.start = begin;
                    auto en = map.find(begin);
                    en->second.end = end;
                } else if (begin == iter && end != iter) { // update just -1
                    auto en = map.find(end);
                    en->second.start = begin;
                } else if (begin != iter) { // update +1
                    auto st = map.find(begin);
                    st->second.end = end;
                }
                map.insert({iter, p});
                diff = end - begin + 1;
            }
            m = max(m, diff);
        }

        return m;
    }
};

LongestConsecutiveSequence test;
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
    vector<int> v{100, 4, 200, 1, 3, 2};
    a.assertEquals(test.longestConsecutive(v), 4);
}

void testcase2() {
    vector<int> v{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    a.assertEquals(test.longestConsecutive(v), 9);
}

void testcase3() {
}