#
# @lc app=leetcode.cn id=228 lang=python3
#
# [228] 汇总区间
#
from typing import List


# @lc code=start
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ans = []
        i, n = 0, len(nums)
        while i < n:
            l = i
            i += 1
            while i < n and nums[i] == nums[i - 1] + 1:
                i += 1
            h = i - 1
            ans.append(f"{nums[l]}->{nums[h]}" if l < h else str(nums[l]))
        return ans


# @lc code=end
