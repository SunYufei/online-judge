#
# @lc app=leetcode.cn id=258 lang=python3
#
# [258] 各位相加
#


# @lc code=start
class Solution:
    def addDigits(self, num: int) -> int:
        # return (num - 1) % 9 + 1 if num else 0
        while num >= 10:
            sum = 0
            while num:
                sum += num % 10
                num //= 10
            num = sum
        return num


# @lc code=end
