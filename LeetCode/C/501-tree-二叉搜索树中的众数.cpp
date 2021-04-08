/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    vector<int> findMode(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<int> a, res;
        dfs(root, a);
        res.push_back(a[0]);
        int max = 1, count = 1;
        for (int i = 1; i < a.size(); ++i) {
            count = a[i - 1] == a[i] ? count + 1 : 1;
            if (count == max)
                res.push_back(a[i]);
            else if (count > max) {
                res.clear();
                res.push_back(a[i]);
                max = count;
            }
        }
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
