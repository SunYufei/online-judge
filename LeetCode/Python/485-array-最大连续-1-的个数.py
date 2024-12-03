#
# @lc app=leetcode.cn id=485 lang=python3
#
# [485] 最大连续 1 的个数
#
from typing import List


# @lc code=start
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans, cur = 0, 0
        for n in nums:
            if n == 0:
                cur = 0
            else:
                cur += 1
                ans = max(cur, ans)
        return ans


# @lc code=end
