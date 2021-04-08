/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

#include "main.h"
// @lc code=start
class Solution {
  public:
    int pathSum(TreeNode *root, int sum) {
        if (root == nullptr)
            return 0;
        int res = countPath(root, sum);
        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);
        return res + left + right;
    }

    int countPath(TreeNode *root, int sum) {
        if (root == nullptr)
            return 0;
        sum -= root->val;
        int res = sum == 0 ? 1 : 0;
        return res + countPath(root->left, sum) + countPath(root->right, sum);
    }
};
// @lc code=end
