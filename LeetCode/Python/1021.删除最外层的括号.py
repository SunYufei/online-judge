#
# @lc app=leetcode.cn id=1021 lang=python3
#
# [1021] 删除最外层的括号
#


# @lc code=start
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans = []
        level = 0
        for c in list(s):
            if c == ")":
                level -= 1
            if level >= 1:
                ans.append(c)
            if c == "(":
                level += 1
        return "".join(ans)


# @lc code=end
