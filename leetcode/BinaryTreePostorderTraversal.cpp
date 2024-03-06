// Authored by Jie Huang
// 2/3/24
// 145. Binary Tree Postorder Traversal

#include "cpp_header.h"
#include <stack>

using std::stack;

void testcase1();
void testcase2();
void testcase3();

class BinaryTreePostorderTraversal {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v{};
        if (root != NULL) {
            stack<TreeNode *> stack{};
            stack.push(root);
            TreeNode *prev = NULL;
            while (!stack.empty()) {
                TreeNode *curr = stack.top();
                if (prev == NULL || prev->left == curr || prev->right == curr) {
                    if (curr->left != NULL) {
                        stack.push(curr->left);
                    } else if (curr->right != NULL) {
                        stack.push(curr->right);
                    } else {
                        stack.pop();
                        v.push_back(curr->val);
                    }
                } else if (curr->left == prev) {
                    if (curr->right != NULL) {
                        stack.push(curr->right);
                    } else {
                        stack.pop();
                        v.push_back(curr->val);
                    }
                } else if (curr->right == prev) {
                    stack.pop();
                    v.push_back(curr->val);
                }
                prev = curr;
            }
        }
        return v;
    }
};

BinaryTreePostorderTraversal test;
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
    vector<int> v{3, 2, 1};
    a.assertEquals(test.postorderTraversal(root), v);
}

void testcase2() {
    int arr[]{};
    TreeNode *root = c.createTreeNodeTree(arr, 0);
    vector<int> v{};
    a.assertEquals(test.postorderTraversal(root), v);
}

void testcase3() {
    int arr[]{1};
    TreeNode *root = c.createTreeNodeTree(arr, 1);
    vector<int> v{1};
    a.assertEquals(test.postorderTraversal(root), v);
}