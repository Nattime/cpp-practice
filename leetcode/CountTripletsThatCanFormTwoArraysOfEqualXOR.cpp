// Authored by Jie Huang
// 5/30/24
// 1442. Count Triplets That Can Form Two Arrays of Equal XOR

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class CountTripletsThatCanFormTwoArraysOfEqualXOR {
  public:
    int countTriplets(vector<int> &arr) {
        int ret{0};
        int len = arr.size();
        for (int i = 0; i < len; i++) {
            int sum = arr[i];
            for (int k = i + 1; k < len; k++) {
                sum = sum ^ arr[k];
                if (sum == 0) {
                    ret += (k - i);
                }
            }
        }
        return ret;
    }
};

CountTripletsThatCanFormTwoArraysOfEqualXOR test;
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
    vector<int> v{2, 3, 1, 6, 7};
    a.assertEquals(test.countTriplets(v), 4);
}

void testcase2() {
    vector<int> v{1, 1, 1, 1, 1};
    a.assertEquals(test.countTriplets(v), 10);
}

void testcase3() {
}