#
# @lc app=leetcode.cn id=917 lang=python3
#
# [917] 仅仅反转字母
#


# @lc code=start
class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        s = list(s)
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and not s[l].isalpha():
                l += 1
            while l < r and not s[r].isalpha():
                r -= 1
            s[l], s[r] = s[r], s[l]
            l, r = l + 1, r - 1
        return "".join(s)


# @lc code=end
