/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto t = q.front();
                q.pop();
                if (size == 0)
                    res.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
        }
        return res;
    }
};
// @lc code=end
