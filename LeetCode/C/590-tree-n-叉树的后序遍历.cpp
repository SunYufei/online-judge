/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    vector<int> postorder(Node *root) {
        vector<int> res;
        post(root, res);
        return res;
    }

    void post(Node *root, vector<int> &res) {
        if (root == nullptr)
            return;
        for (auto child : root->children)
            post(child, res);
        res.push_back(root->val);
    }
};
// @lc code=end
