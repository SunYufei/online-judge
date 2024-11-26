#
# @lc app=leetcode.cn id=268 lang=python3
#
# [268] 丢失的数字
#
from typing import List


# @lc code=start
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        total = n * (n + 1) // 2
        return total - sum(nums)


# @lc code=end
