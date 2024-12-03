#
# @lc app=leetcode.cn id=128 lang=python3
#
# [128] 最长连续序列
#
from typing import List


# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        nums.sort()
        l, r, ans = 0, 1, 0
        while r < len(nums):
            if nums[r] - nums[r - 1] == 1:
                r += 1
            elif nums[r] - nums[r - 1] == 0:
                r += 1
                l += 1
            else:
                ans = max(ans, r - l)
                l = max(r, 0)
                r += 1
        return max(ans, r - l)


# @lc code=end
