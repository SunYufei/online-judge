#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#
# https://leetcode.cn/problems/valid-parentheses/description/
#
# algorithms
# Easy (44.33%)
# Likes:    4589
# Dislikes: 0
# Total Accepted:    2M
# Total Submissions: 4.5M
# Testcase Example:  '"()"'
#
# 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
#
# 有效字符串需满足：
#
#
# 左括号必须用相同类型的右括号闭合。
# 左括号必须以正确的顺序闭合。
# 每个右括号都有一个对应的相同类型的左括号。
#
#
#
#
# 示例 1：
#
#
# 输入：s = "()"
#
# 输出：true
#
#
# 示例 2：
#
#
# 输入：s = "()[]{}"
#
# 输出：true
#
#
# 示例 3：
#
#
# 输入：s = "(]"
#
# 输出：false
#
#
# 示例 4：
#
#
# 输入：s = "([])"
#
# 输出：true
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 10^4
# s 仅由括号 '()[]{}' 组成
#
#
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
