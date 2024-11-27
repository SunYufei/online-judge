#
# @lc app=leetcode.cn id=938 lang=python3
#
# [938] 二叉搜索树的范围和
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
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if root is None:
            return 0
        if root.val > high:
            return self.rangeSumBST(root.left, low, high)
        if root.val < low:
            return self.rangeSumBST(root.right, low, high)
        return (
            root.val
            + self.rangeSumBST(root.left, low, high)
            + self.rangeSumBST(root.right, low, high)
        )

    # def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
    #     ans = 0
    #     q = [root]
    #     while len(q) > 0:
    #         node = q.pop(0)
    #         if node is None:
    #             continue
    #         if node.val > high:
    #             q.append(node.left)
    #         elif node.val < low:
    #             q.append(node.right)
    #         else:
    #             ans += node.val
    #             q.append(node.left)
    #             q.append(node.right)
    #     return ans


# @lc code=end
