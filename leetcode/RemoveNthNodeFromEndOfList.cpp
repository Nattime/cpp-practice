// Authored by Jie Huang
// 3/5/24
// 19. Remove Nth Node From End of List

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

class RemoveNthNodeFromEndOfList {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *f = new ListNode(0, head);
        ListNode *trav = head->next;
        if (trav == NULL) {
            return NULL;
        }
        for (int i = 1; i < n; i++) {
            trav = trav->next;
        }
        head = f;
        while (trav != NULL) {
            head = head->next;
            trav = trav->next;
        }
        head->next = head->next->next;
        return f->next;
    }
};

RemoveNthNodeFromEndOfList test;
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
    ListNode *in = c.createListNodeList(v);
    vector<int> v2{1, 2, 3, 5};
    ListNode *out = c.createListNodeList(v2);
    a.assertEquals(test.removeNthFromEnd(in, 2), out);
}

void testcase2() {
    vector<int> v{1};
    ListNode *in = c.createListNodeList(v);
    vector<int> v2{};
    ListNode *out = c.createListNodeList(v2);
    a.assertEquals(test.removeNthFromEnd(in, 1), out);
}

void testcase3() {
    vector<int> v{1, 2};
    ListNode *in = c.createListNodeList(v);
    vector<int> v2{2};
    ListNode *out = c.createListNodeList(v2);
    a.assertEquals(test.removeNthFromEnd(in, 2), out);
}