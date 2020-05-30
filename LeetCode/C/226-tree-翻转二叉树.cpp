/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */
#include "main.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        invert(root);
        return root;
    }

    void invert(TreeNode *root) {
        if (root == nullptr)
            return;
        swap(root->left, root->right);
        invert(root->left);
        invert(root->right);
    }
};
// @lc code=end
