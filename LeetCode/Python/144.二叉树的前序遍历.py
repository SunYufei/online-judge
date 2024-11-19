#
# @lc app=leetcode.cn id=144 lang=python3
#
# [144] 二叉树的前序遍历
#
# https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
#
# algorithms
# Easy (72.42%)
# Likes:    1294
# Dislikes: 0
# Total Accepted:    1.2M
# Total Submissions: 1.6M
# Testcase Example:  '[1,null,2,3]'
#
# 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
#
#
#
# 示例 1：
#
#
# 输入：root = [1,null,2,3]
#
# 输出：[1,2,3]
#
# 解释：
#
#
#
#
# 示例 2：
#
#
# 输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]
#
# 输出：[1,2,4,5,6,7,3,8,9]
#
# 解释：
#
#
#
#
# 示例 3：
#
#
# 输入：root = []
#
# 输出：[]
#
#
# 示例 4：
#
#
# 输入：root = [1]
#
# 输出：[1]
#
#
#
#
# 提示：
#
#
# 树中节点数目在范围 [0, 100] 内
# -100 <= Node.val <= 100
#
#
#
#
# 进阶：递归算法很简单，你可以通过迭代算法完成吗？
#
#
from typing import Optional, List
from node import TreeNode


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        return (
            [root.val]
            + self.preorderTraversal(root.left)
            + self.preorderTraversal(root.right)
        )


# @lc code=end
