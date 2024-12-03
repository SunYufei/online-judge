#
# @lc app=leetcode.cn id=278 lang=python3
#
# [278] 第一个错误的版本
#
def isBadVersion(version: int) -> bool:
    return True


# @lc code=start
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:


class Solution:
    def firstBadVersion(self, n: int) -> int:
        l, r = 1, n
        while l <= r:
            m = (l + r) // 2
            if isBadVersion(m):
                r = m - 1
            else:
                l = m + 1
        return l if isBadVersion(l) else l + 1


# @lc code=end
