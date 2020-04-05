/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node *t = q.front();
                q.pop();
                level.push_back(t->val);
                for (auto child : t->children)
                    if (child)
                        q.push(child);
            }
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end
