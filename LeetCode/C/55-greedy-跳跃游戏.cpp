/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int max_pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_pos)
                return false;
            max_pos = max(max_pos, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end
