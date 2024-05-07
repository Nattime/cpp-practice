// Authored by Jie Huang
// 5/7/24
// 2816. Double a Number Represented as a Linked List

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class DoubleANumberRepresentedAsALinkedList {
  public:
    ListNode *doubleIt(ListNode *head) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (curr != NULL) {
            int sum = curr->val * 2;
            if (sum < 10) {
                curr->val = sum;
            } else if (prev != NULL) {
                curr->val = sum % 10;
                prev->val += 1;
            } else {
                head = new ListNode(1, curr);
                curr->val = sum % 10;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};

DoubleANumberRepresentedAsALinkedList test;
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
    vector<int> v1{1, 8, 9};
    ListNode *output = c.createListNodeList(v1);
    vector<int> v2{3, 7, 8};
    ListNode *expected = c.createListNodeList(v2);
    a.assertEquals(test.doubleIt(output), expected);
}

void testcase2() {
    vector<int> v1{9, 9, 9};
    ListNode *output = c.createListNodeList(v1);
    vector<int> v2{1, 9, 9, 8};
    ListNode *expected = c.createListNodeList(v2);
    a.assertEquals(test.doubleIt(output), expected);
}

void testcase3() {
}