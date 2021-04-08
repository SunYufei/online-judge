/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
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
                q.pop();
                level.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
