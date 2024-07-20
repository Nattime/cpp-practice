// Authored by Jie Huang
// 7/20/24
// 2196. Create Binary Tree From Descriptions

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

class CreateBinaryTreeFromDescriptions {
  public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        unordered_map<TreeNode *, TreeNode *> map;
        unordered_map<int, TreeNode *> val;
        for (const vector<int> &v : descriptions) {
            const int p = v[0];
            const int c = v[1];
            const bool isLeft = v[2];
            TreeNode *parent = val.count(p) ? val[p] : (val[p] = new TreeNode(p));
            TreeNode *child = val.count(c) ? val[c] : (val[c] = new TreeNode(c));
            map[child] = parent;
            if (isLeft) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        TreeNode *root = map.begin()->second;
        while (map.count(root)) {
            root = map[root];
        }
        return root;
    }
};

CreateBinaryTreeFromDescriptions test;
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
    int in[]{50, 20, 80, 15, 17, 19};
    TreeNode *output = c.createTreeNodeTree(in, 6);
    vector<vector<int>> v{{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    TreeNode *input = test.createBinaryTree(v);
    a.assertEquals(input, output);
}

void testcase2() {
    int in[]{1, 2, NULL, NULL, 3, 4};
    TreeNode *output = c.createTreeNodeTree(in, 6);
    vector<vector<int>> v{{1, 2, 1}, {2, 3, 0}, {3, 4, 1}};
    TreeNode *input = test.createBinaryTree(v);
    a.assertEquals(input, output);
}

void testcase3() {
    int in[]{74, 85, 39, 82, NULL, 13, 70, 38};
    TreeNode *output = c.createTreeNodeTree(in, 8);
    vector<vector<int>> v{{85, 82, 1}, {74, 85, 1}, {39, 70, 0}, {82, 38, 1}, {74, 39, 0}, {39, 13, 1}};
    TreeNode *input = test.createBinaryTree(v);
    a.assertEquals(input, output);
}