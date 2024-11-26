#
# @lc app=leetcode.cn id=67 lang=python3
#
# [67] 二进制求和
#


# @lc code=start
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a, b = list(a)[::-1], list(b)[::-1]
        ans = []
        m, n = len(a), len(b)
        i, j = 0, 0
        carry = 0
        while i < m or j < n:
            carry += int(a[i]) if i < m else 0
            carry += int(b[j]) if j < n else 0
            i, j = i + 1, j + 1
            ans.append(carry % 2)
            carry >>= 1
        while carry > 0:
            ans.append(carry % 2)
            carry >>= 1
        return "".join(map(str, ans[::-1]))


# @lc code=end
