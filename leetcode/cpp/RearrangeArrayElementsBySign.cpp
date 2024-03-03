// Authored by Jie Huang
// 2/14/24
// 2149. Rearrange Array Elements by Sign

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class RearrangeArrayElementsBySign {
  public:
    vector<int> rearrangeArray(vector<int> &nums) {
        vector<int> ret(nums.size());
        int pos{0};
        int neg{1};

        for(int iter : nums){
            if(iter < 0){
                ret[neg] = iter;
                neg += 2;
            }else{
                ret[pos] = iter;
                pos += 2;
            }
        }

        return ret;
    }
};

RearrangeArrayElementsBySign test;
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
    vector<int> nums{3, 1, -2, -5, 2, -4};
    vector<int> ans{3, -2, 1, -5, 2, -4};
    a.assertEquals(test.rearrangeArray(nums), ans);
}

void testcase2() {
    vector<int> nums{-1, 1};
    vector<int> ans{1, -1};
    a.assertEquals(test.rearrangeArray(nums), ans);
}

void testcase3() {
}