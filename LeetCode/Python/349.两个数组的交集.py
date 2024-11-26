#
# @lc app=leetcode.cn id=349 lang=python3
#
# [349] 两个数组的交集
#
from typing import List


# @lc code=start
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        d = {}
        for n in nums1:
            d[n] = 1
        for n in nums2:
            if n in d:
                d[n] = d[n] - 1
                if d[n] == 0:
                    ans.append(n)
        return ans

# @lc code=end
