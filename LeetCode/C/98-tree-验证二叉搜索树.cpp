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
    bool isValidBST(TreeNode *root) {
        return recursion(root, LONG_MIN, LONG_MAX);
    }

  private:
    bool recursion(TreeNode *root, long low, long high) {
        if (root == nullptr)
            return true;
        long val = root->val;
        if (val <= low || val >= high)
            return false;
        return recursion(root->left, low, val) &&
               recursion(root->right, val, high);
    }
};
// @lc code=end
