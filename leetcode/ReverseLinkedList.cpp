// Authored by Jie Huang
// 3/21/24
// 206. Reverse Linked List

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

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class ReverseLinkedList {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *root = new ListNode();
        ListNode *trav{};
        while (head != nullptr) {
            trav = head;
            head = head->next;
            trav->next = root->next;
            root->next = trav;
        }
        return root->next;
    }
};

ReverseLinkedList test;
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
    vector<int> v{1, 2, 3, 4, 5};
    ListNode *root = c.createListNodeList(v);
    vector<int> v2{5, 4, 3, 2, 1};
    ListNode *out = c.createListNodeList(v2);
    a.assertEquals(test.reverseList(root), out);
}

void testcase2() {
    vector<int> v{1, 2};
    ListNode *root = c.createListNodeList(v);
    vector<int> v2{2, 1};
    ListNode *out = c.createListNodeList(v2);
    a.assertEquals(test.reverseList(root), out);
}

void testcase3() {
    vector<int> v{};
    ListNode *root = c.createListNodeList(v);
    vector<int> v2{};
    ListNode *out = c.createListNodeList(v2);
    a.assertEquals(test.reverseList(root), out);
}