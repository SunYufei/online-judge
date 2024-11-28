#
# @lc app=leetcode.cn id=724 lang=python3
#
# [724] 寻找数组的中心下标
#
from typing import List


# @lc code=start
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        l, t, n = 0, sum(nums), len(nums)
        for i in range(n):
            if 2 * l + nums[i] == t:
                return i
            l += nums[i]
        return -1


# @lc code=end
