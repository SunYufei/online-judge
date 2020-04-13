/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode *root) {
        int res = 1;
        dfs(root, res);
        return res - 1;
    }

  private:
    int dfs(TreeNode *root, int &res) {
        if (root == nullptr)
            return 0;
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        res = max(res, l + r + 1);
        return max(l, r) + 1;
    }
};
// @lc code=end
