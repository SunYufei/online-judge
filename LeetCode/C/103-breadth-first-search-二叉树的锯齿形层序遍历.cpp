/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        int i = 0;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            while (size--) {
                auto t = q.front();
                level.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                q.pop();
            }
            if (i++ % 2 == 1)
                reverse(level.begin(), level.end());
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end
