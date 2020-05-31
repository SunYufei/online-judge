/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    string tree2str(TreeNode *t) {
        if (t == nullptr)
            return "";
        string res = to_string(t->val);
        if (t->left) {
            res += "(";
            res += tree2str(t->left);
            res += ")";
        }
        if (t->right) {
            if (t->left == nullptr)
                res += "()";
            res += "(";
            res += tree2str(t->right);
            res += ")";
        }
        return res;
    }
};
// @lc code=end
