// Authored by Jie Huang
// 5/10/24
// 786. K-th Smallest Prime Fraction

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class KthSmallestPrimeFraction {
  public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        int len = arr.size();
        double l{0.0}, r{1.0}, m{0.0};
        vector<int> ret{0, 0};
        while (l < r) {
            m = l + (r - l) / 2;
            int n{1}, sum{0}, numerator{0}, denominator{0};
            double frac{0.0};
            for (int i{0}; i < len; i++) {
                while (n < len && arr[i] >= arr[n] * m) {
                    n++;
                }
                sum += len - n;
                if (n < len && frac < arr[i] * 1.0 / arr[n]) {
                    frac = arr[i] * 1.0 / arr[n];
                    numerator = i;
                    denominator = n;
                }
            }
            if (sum == k) {
                return {arr[numerator], arr[denominator]};
            }
            if (sum > k) {
                r = m;
            } else {
                l = m;
            }
        }
        return ret;
    }
};

KthSmallestPrimeFraction test;
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
    vector<int> in{1, 2, 3, 5};
    vector<int> out{2, 5};
    a.assertEquals(test.kthSmallestPrimeFraction(in, 3), out);
}

void testcase2() {
    vector<int> in{1, 7};
    vector<int> out{1, 7};
    a.assertEquals(test.kthSmallestPrimeFraction(in, 1), out);
}

void testcase3() {
}