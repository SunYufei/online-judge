/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;

        function<void(TreeNode *, int)> dfs = [&](TreeNode *node, int level) {
            if (node == nullptr)
                return;
            if (level == res.size())
                res.emplace_back(vector<int>{});
            res[level].emplace_back(node->val);
            dfs(node->left, level + 1);
            dfs(node->right, level + 1);
        };

        dfs(root, 0);
        return res;
    }
};
// @lc code=end
