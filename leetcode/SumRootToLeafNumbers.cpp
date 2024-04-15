// Authored by Jie Huang
// 4/15/24
// 129. Sum Root to Leaf Numbers

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

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class SumRootToLeafNumbers {
  private:
    int helper(TreeNode *node, int num) {
        if (node == NULL) {
            return 0;
        }
        num = num * 10 + node->val;
        if (node->left == NULL && node->right == NULL) {
            return num;
        }
        return helper(node->left, num) + helper(node->right, num);
    }
  public:
    int sumNumbers(TreeNode *root) {
        return helper(root, 0);
    }
};

SumRootToLeafNumbers test;
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
    int arr[]{1, 2, 3};
    TreeNode *root = c.createTreeNodeTree(arr, 3);
    a.assertEquals(test.sumNumbers(root), 25);
}

void testcase2() {
    int arr[]{4, 9, 0, 5, 1};
    TreeNode *root = c.createTreeNodeTree(arr, 5);
    a.assertEquals(test.sumNumbers(root), 1026);
}

void testcase3() {
}