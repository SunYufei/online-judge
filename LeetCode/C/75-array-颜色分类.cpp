/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int count[3] = {0};
        for (int num : nums)
            ++count[num];
        nums.clear();
        for (int i = 0; i < 3; i++)
            while (count[i]--)
                nums.push_back(i);
    }
};
// @lc code=end
