#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#
from typing import List


# @lc code=start
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [0] * n
        if obstacleGrid[0][0] == 0:
            dp[0] = 1
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    dp[j] = 0
                    continue
                if j - 1 >= 0 and obstacleGrid[i][j - 1] == 0:
                    dp[j] += dp[j - 1]
        return dp[n - 1]


# @lc code=end
