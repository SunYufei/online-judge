/*
 * @lc app=leetcode.cn id=103 lang=golang
 *
 * [103] 二叉树的锯齿形层次遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func zigzagLevelOrder(root *TreeNode) [][]int {
	var res = [][]int{}
	var q = []*TreeNode{}
	if root != nil {
		q = append(q, root)
	}
	var reverse = false
	for len(q) != 0 {
		var level = []int{}
		var size = len(q)
		for i := 0; i < size; i++ {
			var front = q[0]
			q = q[1:]
			level = append(level, front.Val)
			if front.Left != nil {
				q = append(q, front.Left)
			}
			if front.Right != nil {
				q = append(q, front.Right)
			}
		}
		if reverse {
			var l, r = 0, size - 1
			for l < r {
				level[l], level[r] = level[r], level[l]
				l++
				r--
			}
		}
		reverse = !reverse
		res = append(res, level)
	}
	return res
}
// @lc code=end

