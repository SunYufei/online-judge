/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
    bool isSubtree(TreeNode *s, TreeNode *t) { return dfs(s, t); }

  private:
    bool dfs(TreeNode *s, TreeNode *t) {
        if (s == nullptr)
            return false;
        return check(s, t) || dfs(s->left, t) || dfs(s->right, t);
    }

    bool check(TreeNode *s, TreeNode *t) {
        if (s == nullptr && t == nullptr)
            return true;
        if (s && !t || !s && t || s->val != t->val)
            return false;
        return check(s->left, t->left) && check(s->right, t->right);
    }
};
// @lc code=end
