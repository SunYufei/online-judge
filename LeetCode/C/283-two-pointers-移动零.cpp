/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        int p = 0;
        for (int num : nums)
            if (num != 0)
                nums[p++] = num;
        while (p < nums.size())
            nums[p++] = 0;
    }
};
// @lc code=end
