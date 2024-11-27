#
# @lc app=leetcode.cn id=338 lang=python3
#
# [338] 比特位计数
#
from typing import List


# @lc code=start
class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0]
        for i in range(1, n + 1):
            ans.append(ans[i & (i - 1)] + 1)
        return ans


# @lc code=end
