/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<bool> vis(nums.size(), false);
        vector<int> level;
        backtrack(nums, vis, level, res);
        return res;
    }

  private:
    void backtrack(const vector<int> &nums, vector<bool> &vis,
                   vector<int> &level, vector<vector<int>> &res) {
        if (level.size() == nums.size()) {
            res.push_back(level);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i])
                continue;
            vis[i] = true;
            level.push_back(nums[i]);
            backtrack(nums, vis, level, res);
            vis[i] = false;
            level.pop_back();
        }
    }
};
// @lc code=end
