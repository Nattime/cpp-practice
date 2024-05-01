// Authored by Jie Huang
// 1/29/24
// 98. Validate Binary Search Tree

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();

class ValidateBinarySearchTree {
    bool helper(TreeNode *root, long min, long max) {
        if (root == NULL) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            return false;
        }
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }

  public:
    bool isValidBST(TreeNode *root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

ValidateBinarySearchTree test;
Create c{};
Print p{};
Assert a{};

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();

    return 0;
}

void testcase1() {
    int arr[]{2, 1, 3};
    TreeNode *root = c.createTreeNodeTree(arr, 3);
    a.assertTrue(test.isValidBST(root));
}

void testcase2() {
    int arr[]{5, 1, 4, NULL, NULL, 3, 6};
    TreeNode *root = c.createTreeNodeTree(arr, 7);
    a.assertEquals(test.isValidBST(root), false);
}