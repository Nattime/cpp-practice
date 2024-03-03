// Authored by Jie Huang
// 1/29/24
// Test Print methods

#include "../leetcode/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();
void testcase4();
void testcase5();

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();
    testcase4();
    testcase5();

    return 0;
}

Create c{};
Print p{};

void testcase1() {
    int arr[] = {3, 9, 20, NULL, NULL, 15, 7};
    TreeNode *t = c.createTreeNodeTree(arr, 7);
    p.printBinaryTree(t);
}

void testcase2() {
    int arr[] = {3};
    TreeNode *t = c.createTreeNodeTree(arr, 1);
    p.printBinaryTree(t);
}

void testcase3() {
    int arr[] = {3, NULL, 1};
    TreeNode *t = c.createTreeNodeTree(arr, 3);
    p.printBinaryTree(t);
}

void testcase4() {
    int arr[] = {3, 4, 1};
    TreeNode *t = c.createTreeNodeTree(arr, 3);
    p.printBinaryTree(t);
}

void testcase5() {
    int arr[] = {3, 4};
    TreeNode *t = c.createTreeNodeTree(arr, 2);
    p.printBinaryTree(t);
}