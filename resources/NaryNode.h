/**
 * @file NaryNode.h
 * @author jiehuang
 * @brief
 * @version 0.1
 * @date 2024-08-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef NARYNODE_H
#define NARYNODE_H

#include <vector>

using std::vector;

struct NaryNode {
    int val;
    vector<NaryNode *> children;
    NaryNode() : val(0), children() {}
    NaryNode(int x) : val(x), children() {}
    NaryNode(int x, vector<NaryNode *> &next) : val(x), children(next) {}
};

#endif