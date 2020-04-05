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
        post(root);
        return res;
    }

  private:
    vector<int> res;

    void post(TreeNode *root) {
        if (root == nullptr)
            return;
        post(root->left);
        post(root->right);
        res.push_back(root->val);
    }
};
// @lc code=end
