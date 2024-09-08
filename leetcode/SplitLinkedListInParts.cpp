// Authored by Jie Huang
// 9/8/24
// 725. Split Linked List in Parts

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

Create c{};
Print p{};
Assert a{};

class SplitLinkedListInParts {
  public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        vector<ListNode *> ret(k);
        ListNode *trav = head;
        int count = 0;
        while (trav != NULL) {
            trav = trav->next;
            count++;
        }
        trav = head;
        if (count < k) {
            for (int i = 0; i < count; i++) {
                ret[i] = trav;
                ListNode *temp = trav;
                trav = trav->next;
                temp->next = NULL;
            }
        } else {
            int rem = count % k;
            for (int i = 0; i < k; i++) {
                ListNode *curr = trav;
                int len = (count / k);
                ret[i] = curr;
                if (rem-- > 0) {
                    len++;
                }
                for (int j = 1; j < len; j++) {
                    trav = trav->next;
                }
                ListNode *temp = trav;
                trav = trav->next;
                temp->next = NULL;
            }
        }
        return ret;
    }
};

SplitLinkedListInParts test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    vector<int> v{1, 2, 3};
    ListNode *root = c.createListNodeList(v);
    vector<ListNode *> expected(5);
    vector<int> v1{1};
    expected[0] = c.createListNodeList(v1);
    vector<int> v2{2};
    expected[1] = c.createListNodeList(v2);
    vector<int> v3{3};
    expected[2] = c.createListNodeList(v3);
    a.assertEquals(test.splitListToParts(root, 5), expected);
}

void testcase2() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode *root = c.createListNodeList(v);
    vector<ListNode *> expected(3);
    vector<int> v1{1, 2, 3, 4};
    expected[0] = c.createListNodeList(v1);
    vector<int> v2{5, 6, 7};
    expected[1] = c.createListNodeList(v2);
    vector<int> v3{8, 9, 10};
    expected[2] = c.createListNodeList(v3);
    a.assertEquals(test.splitListToParts(root, 3), expected);
}

void testcase3() {
}