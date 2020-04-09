/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode *root) {
        vector<int> order;
        inorder(root, order);
        for (int i = 1; i < order.size(); i++)
            if (order[i] <= order[i - 1])
                return false;
        return true;
    }

  private:
    void inorder(TreeNode *root, vector<int> &order) {
        if (root == nullptr)
            return;
        inorder(root->left, order);
        order.push_back(root->val);
        inorder(root->right, order);
    }
};
// @lc code=end
