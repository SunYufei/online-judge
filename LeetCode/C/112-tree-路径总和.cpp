/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
            return root->val == sum;
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};
// @lc code=end
