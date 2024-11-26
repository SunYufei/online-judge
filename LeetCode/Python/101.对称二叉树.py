#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
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
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def check(p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
            if p is None and q is None:
                return True
            if p is None or q is None or p.val != q.val:
                return False
            return check(p.left, q.right) and check(p.right, q.left)

        return check(root, root)


# @lc code=end
