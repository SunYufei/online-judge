/*
 * @lc app=leetcode.cn id=222 lang=golang
 *
 * [222] 完全二叉树的节点个数
 */
package leetcode

import "math"

// @lc code=start
func countNodes(root *TreeNode) int {
	if root == nil {
		return 0
	}
	var d = computeDepth(root)
	if d == 0 {
		return 1
	}
	var left, right = 1, int(math.Pow(2, float64(d))) - 1
	for left <= right {
		var pivot = left + (right - left) / 2
		if exists(pivot, d, root) {
			left = pivot + 1
		} else {
			right = pivot - 1
		}
	}
	return int(math.Pow(2, float64(d))) - 1 + left
}

func computeDepth(root *TreeNode) int {
	var d = 0
	for root.Left != nil {
		root = root.Left
		d++
	}
	return d
}

func exists(idx,d int, node *TreeNode) bool {
	var left, right = 0, int(math.Pow(2, float64(d))) - 1
	var pivot int
	for i := 0; i < d; i++ {
		pivot = left + (right - left) / 2
		if idx <= pivot {
			node = node.Left
			right = pivot
		} else {
			node = node.Right
			left = pivot + 1
		}
	}
	return node != nil
}
// @lc code=end

