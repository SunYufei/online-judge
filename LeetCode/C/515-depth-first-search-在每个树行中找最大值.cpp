/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<int> largestValues(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int level = INT_MIN;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto t = q.front();
                q.pop();
                level = max(level, t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end
