/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    bool findTarget(TreeNode *root, int k) {
        if (root == nullptr)
            return false;
        unordered_set<int> s;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (s.insert(k - t->val).second == false)
                return true;
            s.insert(t->val);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        return false;
    }
};
// @lc code=end
