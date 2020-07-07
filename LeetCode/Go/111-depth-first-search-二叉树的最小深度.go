/*
 * @lc app=leetcode.cn id=111 lang=golang
 *
 * [111] 二叉树的最小深度
 */
package leetcode

import "math"

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	var res = math.MaxInt64
	dfs(root, 1, &res)
	return res
}

func dfs(root *TreeNode, level int, res *int) {
	if root.Left == nil && root.Right == nil {
		*res = min(*res, level)
		return
	}
	if root.Left != nil {
		dfs(root.Left, level + 1, res)
	}
	if root.Right != nil {
		dfs(root.Right, level + 1, res)
	}
}

func min(i, j int) int {
	if i < j {
		return i
	} else {
		return j
	}
}
// @lc code=end

