#
# @lc app=leetcode.cn id=509 lang=python3
#
# [509] 斐波那契数
#


# @lc code=start
class Solution:
    def fib(self, n: int) -> int:
        if n <= 1:
            return n
        p, q = 0, 1
        for _ in range(1, n):
            q = p + q
            p = q - p
        return q


# @lc code=end
