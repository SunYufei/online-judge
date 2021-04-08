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
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            ++res;
            int size = q.size();
            while (size--) {
                auto t = q.front();
                q.pop();
                for (auto child : t->children)
                    if (child)
                        q.push(child);
            }
        }
        return res;
    }
};
// @lc code=end
