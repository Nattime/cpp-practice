// Authored by Jie Huang
// 7/20/24
// 1530. Number of Good Leaf Nodes Pairs

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

class NumberOfGoodLeafNodesPairs {
  private:
    int count = 0;
    vector<int> dfs(TreeNode *node, int distance) {
        vector<int> arr(distance + 1);
        if (node == NULL) {
            return arr;
        }
        if (node->left == NULL && node->right == NULL) {
            arr[0] = 1;
            return arr;
        }
        vector<int> arrLeft = dfs(node->left, distance);
        vector<int> arrRight = dfs(node->right, distance);
        for (int i = 0; i < distance; ++i) {
            for (int j = 0; j < distance; ++j) {
                if (i + j + 2 <= distance) {
                    count += arrLeft[i] * arrRight[j];
                }
            }
        }
        for (int i = 0; i < distance; ++i) {
            arr[i + 1] = arrLeft[i] + arrRight[i];
        }
        return arr;
    }
  public:
    int countPairs(TreeNode *root, int distance) {
        count = 0;
        dfs(root, distance);
        return count;
    }
};

NumberOfGoodLeafNodesPairs test;
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
    TreeNode *input = c.createTreeNodeTree(new int[5]{1, 2, 3, NULL, 4}, 5);
    a.assertEquals(test.countPairs(input, 3), 1);
}

void testcase2() {
    TreeNode *input = c.createTreeNodeTree(new int[7]{1, 2, 3, 4, 5, 6, 7}, 7);
    a.assertEquals(test.countPairs(input, 3), 2);
}

void testcase3() {
    TreeNode *input = c.createTreeNodeTree(new int[13]{7, 1, 4, 6, NULL, 5, 3, NULL, NULL, NULL, NULL, NULL, 2}, 13);
    a.assertEquals(test.countPairs(input, 3), 1);
}