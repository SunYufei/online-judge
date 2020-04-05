/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        pre(root);
        return res;
    }

  private:
    vector<int> res;

    void pre(TreeNode *root) {
        if (root == nullptr)
            return;
        res.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
};
// @lc code=end
