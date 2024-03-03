/**
 * @file ListNode.h
 * @author jiehuang
 * @brief
 * @version 0.1
 * @date 2024-02-21
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    bool operator()(const ListNode *a, const ListNode *b) {
        return a->val > b->val;
    }
};

#endif