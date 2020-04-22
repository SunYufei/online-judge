/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode *root) {
        unordered_map<int, int> rightDepth;
        int maxDepth = -1;
        queue<TreeNode *> node;
        queue<int> depth;
        node.push(root);
        depth.push(0);
        while (!node.empty()) {
            auto n = node.front();
            node.pop();
            int d = depth.front();
            depth.pop();
            if (n) {
                maxDepth = max(maxDepth, d);
                rightDepth[d] = n->val;
                node.push(n->left);
                node.push(n->right);
                depth.push(d + 1);
                depth.push(d + 1);
            }
        }
        vector<int> res;
        for (int d = 0; d <= maxDepth; ++d)
            res.push_back(rightDepth[d]);
        return res;
    }
};
// @lc code=end
