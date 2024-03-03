// Authored by Jie Huang
// 1/30/24
// 94. Binary Tree Inorder Traversal

#include "cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class BinaryTreeInorderTraversal {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret{};
        helper(root, ret);
        return ret;
    }
    void helper(TreeNode *root, vector<int> &v) {
        if (root != nullptr) {
            helper(root->left, v);
            v.push_back(root->val);
            helper(root->right, v);
        }
    }
};

BinaryTreeInorderTraversal test;
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
    int arr[]{1, NULL, 2, 3};
    TreeNode *root = c.createTreeNodeTree(arr, 4);
    vector<int> output{1, 3, 2};
    a.assertEquals(test.inorderTraversal(root), output);
}

void testcase2() {
    int arr[]{};
    TreeNode *root = c.createTreeNodeTree(arr, 0);
    vector<int> output{};
    a.assertEquals(test.inorderTraversal(root), output);
}

void testcase3() {
    int arr[]{1};
    TreeNode *root = c.createTreeNodeTree(arr, 1);
    vector<int> output{1};
    a.assertEquals(test.inorderTraversal(root), output);
}