// Authored by Jie Huang
// 9/6/24
// 3217. Delete Nodes From Linked List Present in Array

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

Create c{};
Print p{};
Assert a{};

class DeleteNodesFromLinkedListPresentInArray {
  public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head) {
        int maxNum = -1;
        for (int iter : nums) {
            maxNum = max(maxNum, iter);
        }
        vector<bool> arr(maxNum + 1, false);
        for (int iter : nums) {
            arr[iter] = true;
        }
        ListNode *first = new ListNode(0, head);
        ListNode *trav = first;
        while (trav != NULL) {
            bool isIn = false;
            if (trav->next != NULL) {
                int n = trav->next->val;
                if (n <= maxNum && arr[n]) {
                    isIn = true;
                    trav->next = trav->next->next;
                }
            }
            if (!isIn) {
                trav = trav->next;
            }
        }
        return first->next;
    }
};

DeleteNodesFromLinkedListPresentInArray test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    vector<int> in = {1, 2, 3, 4, 5};
    ListNode *root = c.createListNodeList(in);
    vector<int> out = {4, 5};
    ListNode *expected = c.createListNodeList(out);
    vector<int> nums{1, 2, 3};
    a.assertEquals(test.modifiedList(nums, root), expected);
}

void testcase2() {
    vector<int> in = {1, 2, 1, 2, 1, 2};
    ListNode *root = c.createListNodeList(in);
    vector<int> out = {2, 2, 2};
    ListNode *expected = c.createListNodeList(out);
    vector<int> nums{1};
    a.assertEquals(test.modifiedList(nums, root), expected);
}

void testcase3() {
    vector<int> in = {1, 2, 3, 4};
    ListNode *root = c.createListNodeList(in);
    vector<int> out = {1, 2, 3, 4};
    ListNode *expected = c.createListNodeList(out);
    vector<int> nums{5};
    a.assertEquals(test.modifiedList(nums, root), expected);
}