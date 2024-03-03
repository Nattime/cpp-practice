// Authored by Jie Huang
// 1/25/24
// 645. Set Mismatch

#include "cpp_header.h"

void testcase1();
void testcase2();

class SetMismatch {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> ret{0, 0};

        vector<bool> v(nums.size(), false);
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (v[num - 1]) {
                ret[0] = num;
            } else {
                v[num - 1] = true;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!v[i]) {
                ret[1] = i + 1;
                break;
            }
        }

        return ret;
    }
};

SetMismatch test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();

    return 0;
}

void testcase1() {
    vector<int> arr = {1, 2, 2, 4};
    vector<int> ret = test.findErrorNums(arr);
    cout << ret[0] << " " << ret[1] << endl;
}

void testcase2() {
    vector<int> arr = {1, 1};
    vector<int> ret = test.findErrorNums(arr);
    cout << ret[0] << " " << ret[1] << endl;
}