#
# @lc app=leetcode.cn id=136 lang=python3
#
# [136] 只出现一次的数字
#
from typing import List


# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for n in nums:
            ans ^= n
        return ans


# @lc code=end
