#
# @lc app=leetcode.cn id=867 lang=python3
#
# [867] 转置矩阵
#
from typing import List


# @lc code=start
class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        ans = [[0] * m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                ans[j][i] = matrix[i][j]
        return ans


# @lc code=end
