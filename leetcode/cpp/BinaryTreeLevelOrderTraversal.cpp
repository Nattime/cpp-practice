// Authored by Jie Huang
// 1/29/24
// 102. Binary Tree Level Order Traversal

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

class BinaryTreeLevelOrderTraversal {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ret{};
        if (root != nullptr) {
            queue<TreeNode *> q{};
            q.push(root);

            while (!q.empty()) {
                int size = q.size();
                vector<int> v{};
                for (int i = 0; i < size; i++) {
                    TreeNode *curr = q.front();
                    q.pop();
                    v.push_back(curr->val);
                    if (curr->left != nullptr) {
                        q.push(curr->left);
                    }
                    if (curr->right != nullptr) {
                        q.push(curr->right);
                    }
                }
                ret.push_back(v);
            }
        }

        return ret;
    }
};

BinaryTreeLevelOrderTraversal test;
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
    int arr[] = {3, 9, 20, NULL, NULL, 15, 7};
    vector<vector<int>> actual = {{3}, {9, 20}, {15, 7}};
    TreeNode *root1 = c.createTreeNodeTree(arr, 7);

    a.assertEquals(test.levelOrder(root1), actual);
}

void testcase2() {
    int arr[] = {1};
    vector<vector<int>> actual = {{1}};
    TreeNode *root1 = c.createTreeNodeTree(arr, 1);

    a.assertEquals(test.levelOrder(root1), actual);
}

void testcase3() {
    int arr[] = {};
    vector<vector<int>> actual;
    TreeNode *root1 = c.createTreeNodeTree(arr, 0);

    a.assertEquals(test.levelOrder(root1), actual);
}