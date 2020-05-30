/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode *build(vector<int> &nums, int left, int right) {
        if (left > right)
            return nullptr;
        int p = (left + right) / 2;
        auto root = new TreeNode(nums[p]);
        root->left = build(nums, left, p - 1);
        root->right = build(nums, p + 1, right);
        return root;
    }
};
// @lc code=end
