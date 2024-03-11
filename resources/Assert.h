/**
 * @file Assert.h
 * @author jiehuang
 * @brief
 * @version 0.1
 * @date 2024-01-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef ASSERT_H
#define ASSERT_H

#include "../resources/TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;

class Assert {
  private:
    bool assertEqualsHelper(TreeNode *node1, TreeNode *node2) {
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        } else if (node1 != nullptr && node2 != nullptr) {
            if (node1->val == node2->val) {
                return assertEqualsHelper(node1->left, node2->left) && assertEqualsHelper(node1->right, node2->right);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    bool assertEqualsHelper(vector<vector<int>> v1, vector<vector<int>> v2) {
        if (v1.size() != v2.size()) {
            return false;
        }
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i].size() != v2[i].size()) {
                return false;
            }
            for (int j = 0; j < v1[i].size(); j++) {
                if (v1[i][j] != v2[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool assertEqualsHelper(vector<int> v1, vector<int> v2) {
        if (v1.size() != v2.size()) {
            return false;
        }
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
    bool assertEqualsHelper(int num1, int num2) {
        return num1 == num2;
    }
    bool assertEqualsHelper(std::string str1, std::string str2) {
        if(str1.length() != str2.length()){
            return false;
        }
        for(int i = 0; i < str1.length(); i++){
            if(str1[i] != str2[i]){
                return false;
            }
        }
        return true;
    }
    bool assertEqualsHelper(ListNode *l1, ListNode *l2) {
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL && l2 != NULL) {
                return false;
            } else if (l1 != NULL && l2 == NULL) {
                return false;
            } else if (l1->val != l2->val) {
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }

  public:
    void assertEquals(TreeNode *node1, TreeNode *node2) {
        cout << assertEqualsHelper(node1, node2) << endl;
    }
    void assertEquals(vector<vector<int>> v1, vector<vector<int>> v2) {
        cout << assertEqualsHelper(v1, v2) << endl;
    }
    void assertEquals(vector<int> v1, vector<int> v2) {
        cout << assertEqualsHelper(v1, v2) << endl;
    }
    void assertEquals(int num1, int num2) {
        cout << assertEqualsHelper(num1, num2) << endl;
    }
    void assertEquals(ListNode *l1, ListNode *l2) {
        cout << assertEqualsHelper(l1, l2) << endl;
    }
    void assertEquals(std::string str1, std::string str2){
        cout << assertEqualsHelper(str1, str2) << endl;
    }
    void assertTrue(bool b1) {
        cout << (b1 == true) << endl;
    }
    void assertFalse(bool b1) {
        cout << (b1 == false) << endl;
    }
};

#endif