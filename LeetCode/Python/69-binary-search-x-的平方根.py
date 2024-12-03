#
# @lc app=leetcode.cn id=69 lang=python3
#
# [69] x 的平方根
#


# @lc code=start
class Solution:
    def mySqrt(self, x: int) -> int:
        l, r = 0, x
        ans = -1
        while l <= r:
            m = (l + r) >> 1
            if m * m <= x:
                ans = m
                l = m + 1
            else:
                r = m - 1
        return ans


# @lc code=end
