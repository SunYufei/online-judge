/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;

        function<void(TreeNode *)> in = [&](TreeNode *node) {
            if (node == nullptr)
                return;
            in(node->left);
            res.push_back(node->val);
            in(node->right);
        };

        in(root);
        return res;
    }
};
// @lc code=end
