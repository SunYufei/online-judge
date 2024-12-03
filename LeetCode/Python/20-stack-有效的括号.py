#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#


# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        m = {")": "(", "]": "[", "}": "{"}
        stack = []
        for c in s:
            if c in m:
                if len(stack) == 0 or stack[-1] != m[c]:
                    return False
                stack.pop()
            else:
                stack.append(c)
        return len(stack) == 0


# @lc code=end
