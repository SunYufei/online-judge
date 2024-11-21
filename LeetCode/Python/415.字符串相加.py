#
# @lc app=leetcode.cn id=415 lang=python3
#
# [415] 字符串相加
#
# https://leetcode.cn/problems/add-strings/description/
#
# algorithms
# Easy (54.60%)
# Likes:    857
# Dislikes: 0
# Total Accepted:    351.7K
# Total Submissions: 644.1K
# Testcase Example:  '"11"\n"123"'
#
# 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
#
# 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
#
#
#
# 示例 1：
#
#
# 输入：num1 = "11", num2 = "123"
# 输出："134"
#
#
# 示例 2：
#
#
# 输入：num1 = "456", num2 = "77"
# 输出："533"
#
#
# 示例 3：
#
#
# 输入：num1 = "0", num2 = "0"
# 输出："0"
#
#
#
#
#
#
# 提示：
#
#
# 1 <= num1.length, num2.length <= 10^4
# num1 和num2 都只包含数字 0-9
# num1 和num2 都不包含任何前导零
#
#
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
