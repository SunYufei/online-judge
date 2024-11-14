#
# @lc app=leetcode.cn id=66 lang=python3
#
# [66] 加一
#
# https://leetcode.cn/problems/plus-one/description/
#
# algorithms
# Easy (46.29%)
# Likes:    1444
# Dislikes: 0
# Total Accepted:    791.9K
# Total Submissions: 1.7M
# Testcase Example:  '[1,2,3]'
#
# 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
#
# 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
#
# 你可以假设除了整数 0 之外，这个整数不会以零开头。
#
#
#
# 示例 1：
#
#
# 输入：digits = [1,2,3]
# 输出：[1,2,4]
# 解释：输入数组表示数字 123。
#
#
# 示例 2：
#
#
# 输入：digits = [4,3,2,1]
# 输出：[4,3,2,2]
# 解释：输入数组表示数字 4321。
#
#
# 示例 3：
#
#
# 输入：digits = [9]
# 输出：[1,0]
# 解释：输入数组表示数字 9。
# 加 1 得到了 9 + 1 = 10。
# 因此，结果应该是 [1,0]。
#
#
#
#
# 提示：
#
#
# 1 <= digits.length <= 100
# 0 <= digits[i] <= 9
#
#
#
from typing import List


# @lc code=start
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        for i in range(n - 1, -1, -1):
            if digits[i] != 9:
                digits[i] += 1
                for j in range(i + 1, n):
                    digits[j] = 0
                return digits
        return [1] + [0] * n


# @lc code=end
