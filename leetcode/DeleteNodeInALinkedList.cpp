// Authored by Jie Huang
// 5/5/24
// 237. Delete Node in a Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class DeleteNodeInALinkedList {
  public:
    void deleteNode(ListNode *node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

DeleteNodeInALinkedList test;
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
    vector<int> v{4, 5, 1, 9};
    ListNode *list = c.createListNodeList(v);
    ListNode *node = list->next;
    test.deleteNode(node);
    vector<int> v2{4, 1, 9};
    ListNode *expected = c.createListNodeList(v2);
    a.assertEquals(list, expected);
}

void testcase2() {
    vector<int> v{4, 5, 1, 9};
    ListNode *list = c.createListNodeList(v);
    ListNode *node = list->next->next;
    test.deleteNode(node);
    vector<int> v2{4, 5, 9};
    ListNode *expected = c.createListNodeList(v2);
    a.assertEquals(list, expected);
}

void testcase3() {
}