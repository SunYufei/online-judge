/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<int> postorder(Node *root) {
        post(root);
        return res;
    }

  private:
    vector<int> res;
    void post(Node *root) {
        if (root == nullptr)
            return;
        for (auto child : root->children)
            post(child);
        res.push_back(root->val);
    }
};
// @lc code=end
