// Authored by Jie Huang
// 8/12/24
// 703. Kth Largest Element in a Stream

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

Create c{};
Print p{};
Assert a{};

class KthLargestElementInAStream {
  private:
    int kth;
    priority_queue<int, vector<int>, greater<int>> pq;

  public:
    KthLargestElementInAStream(int k, vector<int> &nums) {
        this->kth = k;

        for (int i : nums) {
            if (pq.size() < kth) {
                pq.push(i);
            } else if (i > pq.top()) {
                pq.pop();
                pq.push(i);
            }
        }
    }

    int add(int val) {
        if (pq.size() < kth) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    vector<int> v{4, 5, 8, 2};
    KthLargestElementInAStream *test = new KthLargestElementInAStream(3, v);
    a.assertEquals(test->add(3), 4);
    a.assertEquals(test->add(5), 5);
    a.assertEquals(test->add(10), 5);
    a.assertEquals(test->add(9), 8);
    a.assertEquals(test->add(4), 8);
}

void testcase2() {
}

void testcase3() {
}