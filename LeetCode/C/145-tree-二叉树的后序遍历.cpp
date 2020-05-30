/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;

        function<void(TreeNode *)> post = [&](TreeNode *node) {
            if (node == nullptr)
                return;
            post(node->left);
            post(node->right);
            res.push_back(node->val);
        };

        post(root);
        return res;
    }
};
// @lc code=end
