/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include "main.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    bool isSymmetric(TreeNode *root) { return isMirror(root, root); }

  private:
    bool isMirror(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        if (t1 == nullptr || t2 == nullptr)
            return false;
        return t1->val == t2->val && isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }
};
// @lc code=end
