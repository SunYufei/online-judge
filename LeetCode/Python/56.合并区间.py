#
# @lc app=leetcode.cn id=56 lang=python3
#
# [56] 合并区间
#
from typing import List


# @lc code=start
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        ans = []
        for v in intervals:
            if len(ans) == 0 or ans[-1][1] < v[0]:
                ans.append(v)
            else:
                ans[-1][1] = max(ans[-1][1], v[1])
        return ans


# @lc code=end
