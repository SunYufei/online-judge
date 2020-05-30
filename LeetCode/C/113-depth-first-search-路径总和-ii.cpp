/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        if (root == nullptr)
            return {};
        vector<int> path;
        vector<vector<int>> res;
        dfs(root, sum, path, res);
        return res;
    }

    void dfs(TreeNode *root, int sum, vector<int> &path,
             vector<vector<int>> &res) {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        sum -= root->val;
        if (sum == 0 && root->left == nullptr && root->right == nullptr)
            res.push_back(path);
        dfs(root->left, sum, path, res);
        dfs(root->right, sum, path, res);
        path.pop_back();
    }
};
// @lc code=end
