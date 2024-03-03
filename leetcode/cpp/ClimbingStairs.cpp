// Authored by Jie Huang
// 1/15/24
// 70. Climbing Stairs

#include "cpp_header.h"

void testcase1();
void testcase2();

class ClimbingStairs {
  public:
    int climbStairs(int n) {
        int total{1};
        int prev{0};
        int temp{0};
        for(int i = 0; i < n; i++){
            temp = total;
            total += prev;
            prev = temp;
        }
        return total;
    }
};

ClimbingStairs test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    
    return 0;
}

void testcase1(){
    int n = test.climbStairs(2);
    cout << n << endl;
}

void testcase2(){
    int n = test.climbStairs(3);
    cout << n << endl;
}