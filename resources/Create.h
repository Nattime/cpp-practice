/**
 * @file Create.h
 * @author jiehuang
 * @brief
 * @version 0.1
 * @date 2024-01-27
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef CREATE_H
#define CREATE_H

#include "../resources/ListNode.h"
#include "../resources/Print.h"
#include "../resources/TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::queue;
using std::vector;

class Create {
  private:
    bool isValidBSTHelper(TreeNode *root, long min, long max) {
        if (root == NULL) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            return false;
        }
        return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
    }
    bool isValidBST(TreeNode *root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
    TreeNode *createTreeNodeTreeHelper(int arr[], int size) {
        TreeNode *root = new TreeNode(arr[0]);
        queue<TreeNode *> q{};
        q.push(root);
        for (int i = 1; i < size; i++) {
            TreeNode *curr = q.front();
            q.pop();
            if (arr[i] != NULL) {
                TreeNode *node = new TreeNode(arr[i]);
                curr->left = node;
                q.push(node);
                i++;
                if (i < size) {
                    if (arr[i] != NULL) {
                        TreeNode *n = new TreeNode(arr[i]);
                        curr->right = n;
                        q.push(n);
                    }
                }
            } else {
                i++;
                if (i < size) {
                    if (arr[i] != NULL) {
                        TreeNode *node = new TreeNode(arr[i]);
                        curr->right = node;
                        q.push(node);
                    }
                }
            }
        }
        return root;
    }
    ListNode *createListNodeHelper(vector<int> &v) {
        ListNode *root = new ListNode(0);
        ListNode *trav = root;
        for (int iter : v) {
            trav->next = new ListNode(iter);
            trav = trav->next;
        }
        // Print p{};
        // p.printListNode(root);
        return root->next;
    }

    // TreeNode* createTreeNodeTreeHelper(int arr[], int size) {
    //     TreeNode *root = new TreeNode(arr[0]);
    //     queue<TreeNode*> q{};
    //     q.push(root);

    //     for (int i = 1; i < size; i++) {
    //         TreeNode *curr = q.front();
    //         // cout << "curr: " << curr->val;
    //         q.pop();
    //         // cout << "\tLEFT: i: " << i << "\tarr[i]: " << arr[i];
    //         if (arr[i] != NULL) {
    //             TreeNode *node = new TreeNode(arr[i]);
    //             curr->left = node;
    //             q.push(node);
    //             i++;
    //             if (i < size) {
    //                 // cout << "\tRIGHT: i: " << i << "\tarr[i]: " << arr[i];
    //                 TreeNode* n = new TreeNode(arr[i]);
    //                 curr->right = n;
    //                 q.push(n);
    //             }
    //             // cout << "\t\t\tL: " << curr->left->val << " R: " << curr->right->val;
    //         }else{
    //             // cout << "\tNULL" << endl;
    //             i++;
    //             if(i < size){
    //                 if(arr[i] != NULL){
    //                     // cout << "\tRIGHT: i: " << i << "\tarr[i]: " << arr[i];
    //                     TreeNode *node = new TreeNode(arr[i]);
    //                     curr->right = node;
    //                     q.push(node);
    //                 }
    //             }
    //         }
    //         // cout << endl;
    //     }
    //     // cout << "root: " << root->val << " L: " << root->left->val << " R: " << root->right->val << endl;
    //     return root;
    // }

  public:
    // void createTreeNode(vector<int> v) {
    //     for (vector<int> iter : v) {
    //         for (int it : iter) {
    //             cout << it << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    TreeNode *createTreeNodeTree(int v[]) {
        int size = sizeof(v) / sizeof(int);
        return createTreeNodeTree(v, size);
    }

    TreeNode *createTreeNodeTree(int v[], int size) {
        if (v == NULL || size < 1) {
            return NULL;
        }
        return createTreeNodeTreeHelper(v, size);
    }

    ListNode *createListNodeList(vector<int> &v) {
        if (v.empty() || v.size() < 1) {
            return NULL;
        }
        return createListNodeHelper(v);
    }

    vector<ListNode *> createListNodeList(vector<vector<int>> v) {
        vector<ListNode *> ret{};
        for (auto iter : v) {
            ListNode *root = createListNodeList(iter);
            ret.push_back(root);
        }
        return ret;
    }
};

#endif