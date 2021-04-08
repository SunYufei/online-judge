/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    int minDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int res = INT_MAX;
        if (root->left)
            res = min(minDepth(root->left), res);
        if (root->right)
            res = min(minDepth(root->right), res);
        return res + 1;
    }
};
// @lc code=end
