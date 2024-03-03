// Authored by Jie Huang
// 2/16/24
// 1481. Least Number of Unique Integers after K Removals

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class LeastNumberOfUniqueIntegersAfterKRemovals {
  public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
        vector<int> vec{};
        int in = 0;

        unordered_map<int, int> map{};

        for (int iter : arr) {
            auto index = map.find(iter);
            if (index == map.end()) {
                map.insert({iter, in++});
                vec.push_back(1);
            } else {
                vec[index->second]++;
            }
        }

        sort(vec.begin(), vec.end());

        int i = 0;
        while (k > 0) {
            k -= vec[i++];
            if (k == 0) {
                break;
            } else if (k < 0) {
                i--;
                break;
            }
        }
        return vec.size() - i;
    }
};

LeastNumberOfUniqueIntegersAfterKRemovals test;
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
    vector<int> num{5, 5, 4};
    a.assertEquals(test.findLeastNumOfUniqueInts(num, 1), 1);
}

void testcase2() {
    vector<int> num{4, 3, 1, 1, 3, 3, 2};
    a.assertEquals(test.findLeastNumOfUniqueInts(num, 3), 2);
}

void testcase3() {
}