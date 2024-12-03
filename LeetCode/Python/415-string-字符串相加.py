#
# @lc app=leetcode.cn id=415 lang=python3
#
# [415] 字符串相加
#


# @lc code=start
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        i, j = len(num1) - 1, len(num2) - 1
        carry = 0
        ans = []
        while i >= 0 or j >= 0 or carry > 0:
            x = int(num1[i]) if i >= 0 else 0
            y = int(num2[j]) if j >= 0 else 0
            carry = x + y + carry
            ans.append(carry % 10)
            carry //= 10
            i, j = i - 1, j - 1
        ans.reverse()
        return "".join(map(str, ans))


# @lc code=end
