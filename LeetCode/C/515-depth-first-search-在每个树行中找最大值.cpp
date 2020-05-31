/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode *root, int level, vector<int> &res) {
        if (res.size() == level)
            res.push_back(root->val);
        res[level] = max(res[level], root->val);
        if (root->left)
            dfs(root->left, level + 1, res);
        if (root->right)
            dfs(root->right, level + 1, res);
    }
};
// @lc code=end
