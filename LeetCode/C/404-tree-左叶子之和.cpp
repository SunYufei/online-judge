/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

#include "main.h"
// @lc code=start
class Solution {
  public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int res = 0;
        dfs(root, false, res);
        return res;
    }

    void dfs(TreeNode *root, bool left, int &res) {
        if (root->left == nullptr && root->right == nullptr) {
            if (left)
                res += root->val;
            return;
        }
        if (root->left)
            dfs(root->left, true, res);
        if (root->right)
            dfs(root->right, false, res);
    }
};
// @lc code=end
