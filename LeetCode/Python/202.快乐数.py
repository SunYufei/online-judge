#
# @lc app=leetcode.cn id=202 lang=python3
#
# [202] 快乐数
#


# @lc code=start
class Solution:
    def isHappy(self, n: int) -> bool:
        def getNext(number: int) -> int:
            sum = 0
            while number > 0:
                number, digit = divmod(number, 10)
                sum += digit**2
            return sum

        slow, fast = n, getNext(n)
        while fast != 1 and slow != fast:
            slow = getNext(slow)
            fast = getNext(getNext(fast))
        return fast == 1


# @lc code=end
