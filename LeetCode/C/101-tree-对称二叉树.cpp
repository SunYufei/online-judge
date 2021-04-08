/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    bool isSymmetric(TreeNode *root) { return check(root, root); }

    bool check(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr || p->val != q->val)
            return false;
        return check(p->left, q->right) && check(p->right, q->left);
    }
};
// @lc code=end
