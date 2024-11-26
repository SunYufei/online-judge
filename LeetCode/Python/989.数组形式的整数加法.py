#
# @lc app=leetcode.cn id=989 lang=python3
#
# [989] 数组形式的整数加法
#
from typing import List


# @lc code=start
class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        n = len(num)
        carry = k
        for i in range(n - 1, -1, -1):
            carry += num[i]
            num[i] = carry % 10
            carry //= 10
        pre = []
        while carry > 0:
            pre.append(carry % 10)
            carry //= 10
        return pre[::-1] + num


# @lc code=end
