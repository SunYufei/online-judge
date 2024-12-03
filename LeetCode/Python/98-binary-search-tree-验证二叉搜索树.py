#
# @lc app=leetcode.cn id=98 lang=python3
#
# [98] 验证二叉搜索树
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
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def check(root: Optional[TreeNode], low: int, high: int) -> bool:
            if root is None:
                return True
            if root.val <= low or root.val >= high:
                return False
            return check(root.left, low, root.val) and check(root.right, root.val, high)

        return check(root, -(2**32), 2**32)


# @lc code=end
