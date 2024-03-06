// Authored by Jie Huang
// 1/27/24
// 617. Merge Two Binary Trees

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

#include "cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class MergeTwoBinaryTrees {
  public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 != NULL && root2 != NULL) {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
        } else if (root2 != NULL) {
            return root2;
        }
        return root1;
    }
};

MergeTwoBinaryTrees test;
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
    int arr1[] = {1, 3, 2, 5};
    int arr2[] = {2, 1, 3, NULL, 4, NULL, 7};
    int output[] = {3, 4, 5, 5, 4, NULL, 7};
    TreeNode *root1 = c.createTreeNodeTree(arr1, 4);
    TreeNode *root2 = c.createTreeNodeTree(arr2, 7);
    TreeNode *t = c.createTreeNodeTree(output, 7);
    TreeNode *out = test.mergeTrees(root1, root2);

    a.assertEquals(t, out);
}

void testcase2() {
    int arr1[] = {1};
    int arr2[] = {1, 2};
    int output[] = {2, 2};
    TreeNode *root1 = c.createTreeNodeTree(arr1, 1);
    TreeNode *root2 = c.createTreeNodeTree(arr2, 2);
    TreeNode *t = c.createTreeNodeTree(output, 2);
    TreeNode *out = test.mergeTrees(root1, root2);

    a.assertEquals(t, out);
}

void testcase3() {
    
}