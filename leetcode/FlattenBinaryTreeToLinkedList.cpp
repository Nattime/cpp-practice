// Authored by Jie Huang
// 6/19/24
// 114. Flatten Binary Tree to Linked List

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class FlattenBinaryTreeToLinkedList {
  public:
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        TreeNode *curr = root;
        TreeNode *prev;
        while (curr != NULL) {
            if (curr->left != NULL) {
                prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

FlattenBinaryTreeToLinkedList test;
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
    TreeNode *input, *output;
    int arr1[] = {1, 2, 5, 3, 4, NULL, 6};
    input = c.createTreeNodeTree(arr1, 7);
    int arr2[] = {1, NULL, 2, NULL, 3, NULL, 4, NULL, 5, NULL, 6};
    output = c.createTreeNodeTree(arr2, 11);
    test.flatten(input);
    a.assertEquals(input, output);
}

void testcase2() {
}

void testcase3() {
}