// Authored by Jie Huang
// 1/29/24
// Test Assert methods

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
    // testcase5();

    return 0;
}

Create c{};
Print p{};
Assert assert{};

void testcase1() {
    int arr1[] = {1, 3, 2, 5};
    int arr2[] = {2, 1, 3, NULL, 4, NULL, 7};
    TreeNode *root1 = c.createTreeNodeTree(arr1, 4);
    TreeNode *root2 = c.createTreeNodeTree(arr2, 7);
    
    assert.assertEquals(root1, root2);
    
}

void testcase2() {
    int arr1[] = {1, 3, 2, 5};
    int arr2[] = {1, 3, 2, 5};
    TreeNode *root1 = c.createTreeNodeTree(arr1, 4);
    TreeNode *root2 = c.createTreeNodeTree(arr2, 4);
    
    assert.assertEquals(root1, root2);
}

void testcase3() {
    int arr1[] = {};
    int arr2[] = {};
    TreeNode *root1 = c.createTreeNodeTree(arr1, 0);
    TreeNode *root2 = c.createTreeNodeTree(arr2, 0);
    
    assert.assertEquals(root1, root2);
}

void testcase4() {
    int arr1[] = {1};
    int arr2[] = {};
    TreeNode *root1 = c.createTreeNodeTree(arr1, 1);
    TreeNode *root2 = c.createTreeNodeTree(arr2, 0);
    
    assert.assertEquals(root1, root2);
}

void testcase5() {
    
}