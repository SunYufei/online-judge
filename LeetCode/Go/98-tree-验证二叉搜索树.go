/*
 * @lc app=leetcode.cn id=98 lang=golang
 *
 * [98] 验证二叉搜索树
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
 **/

import "math"

func isValidBST(root *TreeNode) bool {
	return check(root, math.MinInt64, math.MaxInt64)
}

func check(root *TreeNode, low, high int) bool {
	if root == nil {
		return true
	}
	if root.Val <= low || root.Val >= high {
		return false
	}
	return check(root.Left, low, root.Val) && check(root.Right, root.Val, high)
}

// @lc code=end
