/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

#include "main.h"
// @lc code=start
class Solution {
  public:
    int getMinimumDifference(TreeNode *root) {
        vector<int> a;
        dfs(root, a);
        int res = INT_MAX;
        for (int i = 1; i < a.size(); i++)
            res = min(res, a[i] - a[i - 1]);
        return res;
    }

    void dfs(TreeNode *root, vector<int> &a) {
        if (root == nullptr)
            return;
        dfs(root->left, a);
        a.push_back(root->val);
        dfs(root->right, a);
    }
};
// @lc code=end
