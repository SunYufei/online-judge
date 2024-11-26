#
# @lc app=leetcode.cn id=344 lang=python3
#
# [344] 反转字符串
#
from typing import List


# @lc code=start
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        l, r = 0, len(s) - 1
        while l < r:
            s[l], s[r] = s[r], s[l]
            l, r = l + 1, r - 1


# @lc code=end
