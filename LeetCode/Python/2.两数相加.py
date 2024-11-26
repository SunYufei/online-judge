#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#
from node import ListNode
from typing import Optional


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()
        p = dummy
        carry = 0
        while l1 is not None or l2 is not None:
            if l1 is not None:
                carry += l1.val
                l1 = l1.next
            if l2 is not None:
                carry += l2.val
                l2 = l2.next
            node = ListNode(carry % 10)
            carry //= 10
            p.next = node
            p = p.next
        if carry != 0:
            p.next = ListNode(carry)
        return dummy.next


# @lc code=end
