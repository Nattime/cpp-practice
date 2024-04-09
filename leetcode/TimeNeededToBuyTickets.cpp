// Authored by Jie Huang
// 4/9/24
// 2073. Time Needed to Buy Tickets

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class TimeNeededToBuyTickets {
  public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        int count{0};
        int num{tickets[k]};
        int i{0};
        for (; i <= k; i++) {
            int t{tickets[i]};
            if (t >= num) {
                count += num;
            } else {
                count += tickets[i];
            }
        }
        for (; i < tickets.size(); i++) {
            int t{tickets[i]};
            if (t >= num) {
                count += (num - 1);
            } else {
                count += (tickets[i]);
            }
        }
        return count;
    }
};

TimeNeededToBuyTickets test;
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
    vector<int> v{2, 3, 2};
    a.assertEquals(test.timeRequiredToBuy(v, 2), 6);
}

void testcase2() {
    vector<int> v{5, 1, 1, 1};
    a.assertEquals(test.timeRequiredToBuy(v, 0), 8);
}

void testcase3() {
    vector<int> v{84, 49, 5, 24, 70, 77, 87, 8};
    a.assertEquals(test.timeRequiredToBuy(v, 3), 154);
}