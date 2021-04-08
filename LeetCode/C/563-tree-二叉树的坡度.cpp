/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    int findTilt(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return abs(dfs(root->left) - dfs(root->right)) + findTilt(root->left) +
               findTilt(root->right);
    }

    int dfs(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return root->val + dfs(root->left) + dfs(root->right);
    }
};
// @lc code=end
