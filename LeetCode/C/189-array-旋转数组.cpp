/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n);
        reverse(nums, 0, k);
        reverse(nums, k, n);
    }

  private:
    void reverse(vector<int> &nums, int left, int right) {
        while (left < right)
            swap(nums[left++], nums[--right]);
    }
};
// @lc code=end
