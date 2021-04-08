/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    vector<int> preorder(Node *root) {
        vector<int> res;
        pre(root, res);
        return res;
    }

    void pre(Node *root, vector<int> &res) {
        if (root == nullptr)
            return;
        res.push_back(root->val);
        for (auto child : root->children)
            pre(child, res);
    }
};
// @lc code=end
