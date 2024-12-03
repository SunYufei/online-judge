#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#


# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return 1
        p, q = 1, 1
        for _ in range(n):
            q = p + q
            p = q - p
        return p


# @lc code=end
