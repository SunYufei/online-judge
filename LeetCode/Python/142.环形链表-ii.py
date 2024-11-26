#
# @lc app=leetcode.cn id=142 lang=python3
#
# [142] 环形链表 II
#
from typing import Optional
from node import ListNode

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow, fast = head, head
        while True:
            if not fast or not fast.next:
                return None
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break
        p = head
        while p != slow:
            p = p.next
            slow = slow.next
        return p


# @lc code=end
