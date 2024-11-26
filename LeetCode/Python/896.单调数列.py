#
# @lc app=leetcode.cn id=896 lang=python3
#
# [896] 单调数列
#
from typing import List


# @lc code=start
class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        n = len(nums)
        inc, dec = True, True
        for i in range(n - 1):
            if nums[i] > nums[i + 1]:
                dec = False
            if nums[i] < nums[i + 1]:
                inc = False
        return inc or dec


# @lc code=end
