#
# @lc app=leetcode.cn id=977 lang=python3
#
# [977] 有序数组的平方
#
from typing import List


# @lc code=start
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        i, j, p = 0, n - 1, n - 1
        while i <= j:
            if nums[i] ** 2 > nums[j] ** 2:
                ans[p] = nums[i] ** 2
                i += 1
            else:
                ans[p] = nums[j] ** 2
                j -= 1
            p -= 1
        return ans


# @lc code=end
