/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr)
            return true;
        return abs(height(root->left) - height(root->right)) < 2 &&
               isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode *root) {
        if (root == nullptr)
            return -1;
        return 1 + max(height(root->left), height(root->right));
    }
};
// @lc code=end
