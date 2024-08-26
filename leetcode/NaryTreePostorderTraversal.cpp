// Authored by Jie Huang
// 8/26/24
// 590. N-ary Tree Postorder Traversal

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

Create c{};
Print p{};
Assert a{};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class NaryTreePostorderTraversal {
  private:
    void traverse(NaryNode *root, vector<int> &v) {
        if (root != NULL) {
            vector<NaryNode *> children = root->children;
            for (auto iter : children) {
                traverse(iter, v);
            }
            v.push_back(root->val);
        }
    }

  public:
    vector<int> postorder(NaryNode *root) {
        vector<int> ret{};
        traverse(root, ret);
        return ret;
    }
};

NaryTreePostorderTraversal test;

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    vector<int> v{1, NULL, 3, 2, 4, NULL, 5, 6};
    vector<int> expected{5, 6, 3, 2, 4, 1};
    NaryNode *root = c.createNaryTree(v);
    p.print(root);
    a.assertEquals(test.postorder(root), expected);
}

void testcase2() {
    vector<int> v{1, NULL, 2, 3, 4, 5, NULL, NULL, 6, 7, NULL, 8, NULL, 9, 10, NULL, NULL, 11, NULL, 12, NULL, 13, NULL, NULL, 14};
    vector<int> expected{2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1};
    NaryNode *root = c.createNaryTree(v);
    p.print(root);
    a.assertEquals(test.postorder(root), expected);
}

void testcase3() {
}