// Authored by Jie Huang
// 7/18/24
// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class FindTheMinimumAndMaximumNumberOfNodesBetweenCriticalPoints {
  public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        vector<int> ret{0, 0};
        ret[0] = INT_MAX;
        ret[1] = -1;
        int index = 1;
        int prevMax = -1;
        int maxI = -1;
        ListNode *trav = head->next;
        while (trav != NULL) {
            int num = trav->val;
            if (trav->next != NULL) {
                if ((head->val < num && trav->next->val < num) || (head->val > num && trav->next->val > num)) {
                    if (maxI == -1) {
                        maxI = index;
                    }
                    if (prevMax != -1) {
                        ret[0] = min(ret[0], index - prevMax);
                    }
                    prevMax = index;
                }
            }
            head = head->next;
            trav = trav->next;
            index++;
        }
        if (ret[0] == INT_MAX) {
            ret[0] = -1;
        } else {
            ret[1] = prevMax - maxI;
        }
        return ret;
    }
};

FindTheMinimumAndMaximumNumberOfNodesBetweenCriticalPoints test;
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
    vector<int> v{3, 1};
    vector<int> output{-1, -1};
    ListNode *input = c.createListNodeList(v);
    a.assertEquals(test.nodesBetweenCriticalPoints(input), output);
}

void testcase2() {
    vector<int> v{5, 3, 1, 2, 5, 1, 2};
    vector<int> output{1, 3};
    ListNode *input = c.createListNodeList(v);
    a.assertEquals(test.nodesBetweenCriticalPoints(input), output);
}

void testcase3() {
    vector<int> v{1, 3, 2, 2, 3, 2, 2, 2, 7};
    vector<int> output{3, 3};
    ListNode *input = c.createListNodeList(v);
    a.assertEquals(test.nodesBetweenCriticalPoints(input), output);
}