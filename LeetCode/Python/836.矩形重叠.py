#
# @lc app=leetcode.cn id=836 lang=python3
#
# [836] 矩形重叠
#
from typing import List


# @lc code=start
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        def test(pl, pr, ql, qr):
            return min(pr, qr) > max(pl, ql)

        return test(rec1[0], rec1[2], rec2[0], rec2[2]) and test(
            rec1[1], rec1[3], rec2[1], rec2[3]
        )


# @lc code=end
