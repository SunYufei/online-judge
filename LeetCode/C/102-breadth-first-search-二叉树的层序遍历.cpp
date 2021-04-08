/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            while (size--) {
                auto t = q.front();
                level.push_back(t->val);
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
                q.pop();
            }
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end
