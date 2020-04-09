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
        int m_pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > m_pos)
                return false;
            m_pos = max(m_pos, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end
