#
# @lc app=leetcode.cn id=1025 lang=python3
#
# [1025] 除数博弈
#


# @lc code=start
class Solution:
    def divisorGame(self, n: int) -> bool:
        # return n % 2 == 0
        dp = [False] * (n + 5)
        dp[1], dp[2] = False, True
        for i in range(3, n + 1):
            for j in range(1, i):
                if i % j == 0 and not dp[i - j]:
                    dp[i] = True
                    break
        return dp[n]


# @lc code=end
