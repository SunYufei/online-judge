/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        dfs(root, 0, res);
        for (int i = 0; i < res.size(); i++)
            if (i % 2 == 1)
                reverse(res[i].begin(), res[i].end());
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
