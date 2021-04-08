/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<string> res;
        vector<int> path;
        dfs(root, path, res);
        return res;
    }

    void dfs(TreeNode *root, vector<int> &path, vector<string> &res) {
        if (root->left == nullptr && root->right == nullptr) {
            string level;
            for (auto it = path.begin(); it < path.end(); ++it)
                level += (to_string(*it) + "->");
            level += to_string(root->val);
            res.push_back(level);
            return;
        }
        path.push_back(root->val);
        if (root->left)
            dfs(root->left, path, res);
        if (root->right)
            dfs(root->right, path, res);
        path.pop_back();
    }
};
// @lc code=end
