#
# @lc app=leetcode.cn id=201 lang=python3
#
# [201] 数字范围按位与
#


# @lc code=start
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        while left < right:
            right &= right - 1
        return right


# @lc code=end
