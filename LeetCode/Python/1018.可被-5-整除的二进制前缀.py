#
# @lc app=leetcode.cn id=1018 lang=python3
#
# [1018] 可被 5 整除的二进制前缀
#
from typing import List


# @lc code=start
class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        res = []
        prefix = 0
        for num in nums:
            prefix = ((prefix << 1) + num) % 5
            res.append(prefix == 0)
        return res


# @lc code=end
