// Authored by Jie Huang
// 8/10/24
// 1636. Sort Array by Increasing Frequency

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

Create c{};
Print p{};
Assert a{};

class SortArrayByIncreasingFrequency {
  public:
    vector<int> frequencySort(vector<int> &nums) {
        vector<int> arr(201, 0);
        for (auto it : nums) {
            ++arr[it + 100];
        }
        vector<pair<int, int>> v{};
        for (int i = 0; i < 201; ++i) {
            if (arr[i] > 0) {
                v.push_back(make_pair(arr[i], i - 100));
            }
        }
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) { return a.first == b.first ? ((a.second > b.second)) : b.first > a.first; });
        int iter = 0;
        for (int i = 0; i < v.size(); ++i) {
            int count = v[i].first;
            int num = v[i].second;
            cout << count << " " << num << endl;
            for (; count > 0; --count) {
                nums[iter++] = num;
            }
        }
        return nums;
    }
};

SortArrayByIncreasingFrequency test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    vector<int> v{1, 1, 2, 2, 2, 3};
    vector<int> expected{3, 1, 1, 2, 2, 2};
    a.assertEquals(test.frequencySort(v), expected);
}

void testcase2() {
    vector<int> v{2, 3, 1, 3, 2};
    vector<int> expected{1, 3, 3, 2, 2};
    a.assertEquals(test.frequencySort(v), expected);
}

void testcase3() {
    vector<int> v{-1, 1, -6, 4, 5, -6, 1, 4, 1};
    vector<int> expected{5, -1, 4, 4, -6, -6, 1, 1, 1};
    a.assertEquals(test.frequencySort(v), expected);
}