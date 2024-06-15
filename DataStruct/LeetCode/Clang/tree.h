//
// Created by Eugene on 2022/8/22.
//

#ifndef LEETCODE_TREE_H
#define LEETCODE_TREE_H

#endif //LEETCODE_TREE_H
#pragma once

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
            : val(x), left(left), right(right) {}
};