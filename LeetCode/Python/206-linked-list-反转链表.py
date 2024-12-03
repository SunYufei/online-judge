#
# @lc app=leetcode.cn id=206 lang=python3
#
# [206] 反转链表
#
from typing import Optional
from node import ListNode


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        p = head
        while p is not None:
            q = p
            p = p.next
            q.next = dummy.next
            dummy.next = q
        return dummy.next


# @lc code=end
