/*
 * @lc app=leetcode.cn id=98 lang=golang
 *
 * [98] 验证二叉搜索树
 */

// package leetcode

// @lc code=start
import "math"

func isValidBST(root *TreeNode) bool {
	var check func(*TreeNode, int, int) bool
	check = func(node *TreeNode, low int, high int) bool {
		if root == nil {
			return true
		}
		if root.Val <= low || root.Val >= high {
			return false
		}
		return check(root.Left, low, root.Val) && check(root.Right, root.Val, high)
	}

	return check(root, math.MinInt64, math.MaxInt64)
}

// @lc code=end
