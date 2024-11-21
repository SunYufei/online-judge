#
# @lc app=leetcode.cn id=226 lang=python3
#
# [226] 翻转二叉树
#
# https://leetcode.cn/problems/invert-binary-tree/description/
#
# algorithms
# Easy (81.21%)
# Likes:    1884
# Dislikes: 0
# Total Accepted:    1M
# Total Submissions: 1.3M
# Testcase Example:  '[4,2,7,1,3,6,9]'
#
# 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
#
#
#
# 示例 1：
#
#
#
#
# 输入：root = [4,2,7,1,3,6,9]
# 输出：[4,7,2,9,6,3,1]
#
#
# 示例 2：
#
#
#
#
# 输入：root = [2,1,3]
# 输出：[2,3,1]
#
#
# 示例 3：
#
#
# 输入：root = []
# 输出：[]
#
#
#
#
# 提示：
#
#
# 树中节点数目范围在 [0, 100] 内
# -100 <= Node.val <= 100
#
#
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
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        return root


# @lc code=end
