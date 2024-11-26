#
# @lc app=leetcode.cn id=345 lang=python3
#
# [345] 反转字符串中的元音字母
#


# @lc code=start
class Solution:
    def reverseVowels(self, s: str) -> str:
        m = set(["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"])
        s = list(s)
        l, r = 0, len(s) - 1
        while l < r:
            while s[l] not in m and l < r:
                l += 1
            while s[r] not in m and l < r:
                r -= 1
            s[l], s[r] = s[r], s[l]
            l, r = l + 1, r - 1
        return "".join(s)


# @lc code=end
