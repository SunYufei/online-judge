#
# @lc app=leetcode.cn id=203 lang=python3
#
# [203] 移除链表元素
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
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        p = dummy
        while p.next is not None:
            if p.next.val == val:
                p.next = p.next.next
            else:
                p = p.next
        return dummy.next


# @lc code=end
