#
# @lc app=leetcode.cn id=110 lang=python3
#
# [110] 平衡二叉树
#
from typing import Optional
from node import TreeNode


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def height(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            l = height(node.left)
            r = height(node.right)
            if l == -1 or r == -1 or abs(l - r) > 1:
                return -1
            else:
                return max(l, r) + 1

        return height(root) >= 0


# @lc code=end
