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
        vector<int> res;

        function<void(TreeNode *)> pre = [&](TreeNode *node) {
            if (node == nullptr)
                return;
            res.emplace_back(node->val);
            if (node->left)
                pre(node->left);
            if (node->right)
                pre(node->right);
        };

        pre(root);
        return res;
    }
};
// @lc code=end
