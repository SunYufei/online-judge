#
# @lc app=leetcode.cn id=58 lang=python3
#
# [58] 最后一个单词的长度
#


# @lc code=start
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = list(s)
        n = len(s)
        i = n - 1
        while i >= 0 and s[i] == " ":
            i -= 1
        ans = 0
        while i >= 0 and s[i] != " ":
            ans += 1
            i -= 1
        return ans


# @lc code=end
