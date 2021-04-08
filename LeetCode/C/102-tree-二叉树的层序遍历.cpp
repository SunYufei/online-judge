/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode *root, int level, vector<vector<int>> &res) {
        if (level == res.size())
            res.push_back({});
        res[level].push_back(root->val);
        if (root->left)
            dfs(root->left, level + 1, res);
        if (root->right)
            dfs(root->right, level + 1, res);
    }
};
// @lc code=end
