/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode *root) { return check(root, LONG_MIN, LONG_MAX); }

    bool check(TreeNode *root, long low, long high) {
        if (root == nullptr)
            return true;
        if (root->val <= low || root->val >= high)
            return false;
        return check(root->left, low, root->val) &&
               check(root->right, root->val, high);
    }
};
// @lc code=end
