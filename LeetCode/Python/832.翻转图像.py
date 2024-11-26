#
# @lc app=leetcode.cn id=832 lang=python3
#
# [832] 翻转图像
#
from typing import List


# @lc code=start
class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        ans = []
        for line in image:
            ans.append([1 if n == 0 else 0 for n in line[::-1]])
        return ans


# @lc code=end
