// Authored by Jie Huang
// 2/3/24
// 144. Binary Tree Preorder Traversal

#include "cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class BinaryTreePreorderTraversal {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v{};
        stack<TreeNode*> s{};

        TreeNode *curr = root;
        while(curr != NULL || !s.empty()){
            if(curr == NULL){
                curr = s.top()->right;
                s.pop();
            }else{
                v.push_back(curr->val);
                s.push(curr);
                curr = curr->left;
            }
        }

        return v;
    }
};

BinaryTreePreorderTraversal test;
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
    vector<int> v{1, 2, 3};
    a.assertEquals(test.preorderTraversal(root), v);
}

void testcase2() {
    int arr[]{};
    TreeNode *root = c.createTreeNodeTree(arr, 0);
    vector<int> v{};
    a.assertEquals(test.preorderTraversal(root), v);
}

void testcase3() {
    int arr[]{1};
    TreeNode *root = c.createTreeNodeTree(arr, 1);
    vector<int> v{1};
    a.assertEquals(test.preorderTraversal(root), v);
}