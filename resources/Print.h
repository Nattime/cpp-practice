/**
 * @file Print.h
 * @author jiehuang
 * @brief
 * @version 0.1
 * @date 2024-01-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef PRINT_H
#define PRINT_H

#include "../resources/ListNode.h"
#include "../resources/TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::queue;
using std::vector;

class Print {
  private:
    void printBinaryTreeHelper(TreeNode *root, bool inLine) {
        if (root != NULL) {
            queue<TreeNode *> q{};
            q.push(root);
            while (!q.empty()) {
                int size = q.size();

                for (int i = 0; i < size; i++) {
                    TreeNode *curr = q.front();
                    q.pop();
                    if (curr == nullptr) {
                        cout << "NULL ";
                    } else {
                        cout << curr->val << " ";
                        q.push(curr->left);
                        q.push(curr->right);
                    }
                }
                if (inLine) {
                    cout << endl;
                }
            }
        }
        cout << endl;
    }
    void printListNodeHelper(ListNode *root, bool inLine) {
        while (root != nullptr) {
            cout << root->val << " ";
            if (!inLine) {
                cout << endl;
            }
            root = root->next;
        }
        if (!inLine) {
            cout << endl;
        }
        cout << endl;
    }

  public:
    void print(vector<vector<int>> v) {
        for (vector<int> iter : v) {
            for (int it : iter) {
                cout << it << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void print(vector<int> v) {
        for (int it : v) {
            cout << it << " ";
        }
        cout << endl;
    }

    void print(int v[], int size) {
        for (int i = 0; i < size; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    // void print(int v[]) {
    //     cout << "v[] " << sizeof(v) << endl;
    //     for (int i = 0; v[i] != '\0'; i++) {
    //         cout << v[i] << " ";
    //     }
    //     cout << endl;
    // }

    // void print(int v[]) {
    //     cout << "*v " << sizeof(*v) << endl;
    //     cout << "v[0] " << sizeof(v[0]) << endl;
    //     cout << "v " << sizeof(v) << endl;
    //     cout << "int* " << sizeof(int*) << endl;
    //     // for (int i = 0; !isnan(v[i]); i++) {
    //     for (int i = 0; v[i] != '\0'; i++) {
    //         cout << v[i] << " ";
    //     }
    //     cout << endl;
    // }

    void printBinaryTree(TreeNode *root) {
        printBinaryTree(root, true);
    }

    void printBinaryTree(TreeNode *root, bool inLine) {
        printBinaryTreeHelper(root, inLine);
    }

    void printListNode(ListNode *root) {
        printListNode(root, true);
    }

    void printListNode(ListNode *root, bool inLine) {
        printListNodeHelper(root, inLine);
    }
};

#endif