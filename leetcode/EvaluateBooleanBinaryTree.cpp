// Authored by Jie Huang
// 5/16/24
// 2331. Evaluate Boolean Binary Tree

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class EvaluateBooleanBinaryTree {
  public:
    bool evaluateTree(TreeNode *root) {
        if (root->left == NULL && root->right == NULL) {
            return root->val == 1;
        } else if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        } else {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }
};

EvaluateBooleanBinaryTree test;
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
    int arr[]{2, 1, 3, NULL, NULL, 0, 1};
    TreeNode *root = c.createTreeNodeTree(arr);
    a.assertEquals(test.evaluateTree(root), true);
}

void testcase2() {
    int arr[]{0};
    TreeNode *root = c.createTreeNodeTree(arr);
    a.assertEquals(test.evaluateTree(root), false);
}

void testcase3() {
}