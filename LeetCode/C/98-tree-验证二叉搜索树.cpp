/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
#include "main.h"
// @lc code=start
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
