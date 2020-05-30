/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;

        function<void(TreeNode *)> pre = [&](TreeNode *node) {
            if (node == nullptr)
                return;
            res.push_back(node->val);
            pre(node->left);
            pre(node->right);
        };

        pre(root);
        return res;
    }
};
// @lc code=end
