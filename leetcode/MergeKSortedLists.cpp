// Authored by Jie Huang
// 2/21/24
// 23. Merge k Sorted Lists

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

struct compare {
    bool operator()(const ListNode *a, const ListNode *b) {
        return a->val > b->val;
    }
};

class MergeKSortedLists {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> queue{};
        for (auto *iter : lists) {
            while (iter != NULL) {
                queue.push(iter);
                iter = iter->next;
            }
        }

        ListNode head{0};
        ListNode *trav = &head;

        while (!queue.empty()) {
            trav->next = queue.top();
            queue.pop();
            trav = trav->next;
            trav->next = nullptr;
        }

        return head.next;
    }
};

MergeKSortedLists test;
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
    vector<vector<int>> list{{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode *> input = c.createListNodeList(list);
    vector<int> result{1, 1, 2, 3, 4, 4, 5, 6};
    ListNode *output = c.createListNodeList(result);
    ListNode *res = test.mergeKLists(input);
    a.assertEquals(res, output);
}

void testcase2() {
}

void testcase3() {
}