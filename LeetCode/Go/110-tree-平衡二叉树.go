/*
 * @lc app=leetcode.cn id=110 lang=golang
 *
 * [110] 平衡二叉树
 */
package leetcode
// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return abs(height(root.Left) - height(root.Right)) < 2 && isBalanced(root.Left) && isBalanced(root.Right)
}

func height(root *TreeNode) int {
	if root == nil{
		return -1
	}
	return 1 + max(height(root.Left), height(root.Right))
}

func abs(i int) int {
	if i < 0 {
		return -i
	} else {
		return i
	}
}

func max(i, j int) int{
	if i > j {
		return i
	} else {
		return j
	}
}
// @lc code=end
