/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        pre = preorder;
        for (int i = 0; i < inorder.size(); i++)
            index[inorder[i]] = i;
        return build(0, inorder.size());
    }

  private:
    int preIndex = 0;
    vector<int> pre;
    unordered_map<int, int> index;

    TreeNode *build(int left, int right) {
        if (left == right)
            return nullptr;
        int rootVal = pre[preIndex++];
        TreeNode *root = new TreeNode(rootVal);
        int idx = index[rootVal];
        root->left = build(left, idx);
        root->right = build(idx + 1, right);
        return root;
    }
};
// @lc code=end
