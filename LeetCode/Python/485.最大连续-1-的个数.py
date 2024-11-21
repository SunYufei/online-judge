#
# @lc app=leetcode.cn id=485 lang=python3
#
# [485] 最大连续 1 的个数
#
# https://leetcode.cn/problems/max-consecutive-ones/description/
#
# algorithms
# Easy (61.61%)
# Likes:    443
# Dislikes: 0
# Total Accepted:    260.4K
# Total Submissions: 422.6K
# Testcase Example:  '[1,1,0,1,1,1]'
#
# 给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,1,0,1,1,1]
# 输出：3
# 解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
#
#
# 示例 2:
#
#
# 输入：nums = [1,0,1,1,0,1]
# 输出：2
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 10^5
# nums[i] 不是 0 就是 1.
#
#
#
from typing import List


# @lc code=start
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans, cur = 0, 0
        for n in nums:
            if n == 0:
                cur = 0
            else:
                cur += 1
                ans = max(cur, ans)
        return ans


# @lc code=end
