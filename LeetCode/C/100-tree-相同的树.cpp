/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr || p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end
