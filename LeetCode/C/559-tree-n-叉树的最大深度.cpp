/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    int maxDepth(Node *root) {
        if (root == nullptr)
            return 0;
        int res = 0;
        dfs(root, 1, res);
        return res;
    }

    void dfs(Node *root, int level, int &res) {
        if (root == nullptr)
            return;
        res = max(res, level);
        for (auto child : root->children)
            dfs(child, level + 1, res);
    }
};
// @lc code=end
