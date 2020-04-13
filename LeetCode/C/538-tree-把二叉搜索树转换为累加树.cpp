/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode *convertBST(TreeNode *root) {
        int sum = 0;
        inorder(root, sum);
        return root;
    }

    void inorder(TreeNode *root, int &sum) {
        if (root == nullptr)
            return;
        inorder(root->right, sum);
        root->val += sum;
        sum = root->val;
        inorder(root->left, sum);
    }
};
// @lc code=end
