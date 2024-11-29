#
# @lc app=leetcode.cn id=119 lang=python3
#
# [119] 杨辉三角 II
#
from typing import List


# @lc code=start
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [1] * (rowIndex + 1)
        for i in range(1, rowIndex + 1):
            ans[i] = ans[i - 1] * (rowIndex - i + 1) // i
        return ans


# @lc code=end
