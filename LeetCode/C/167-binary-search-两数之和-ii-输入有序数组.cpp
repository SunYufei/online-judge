/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        if (numbers.size() == 0)
            return {};
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
                return {l + 1, r + 1};
            else if (sum < target)
                ++l;
            else
                --r;
        }
        return {l + 1, r + 1};
    }
};
// @lc code=end
