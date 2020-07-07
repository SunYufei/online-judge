/*
 * @lc app=leetcode.cn id=107 lang=golang
 *
 * [107] 二叉树的层次遍历 II
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
func levelOrderBottom(root *TreeNode) [][]int {
	var res = [][]int{}
	var q = []*TreeNode{}
	if root != nil {
		q = append(q, root)
	}
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
		res = append(res, level)
	}
	var l, r = 0, len(res) - 1
	for l < r {
		res[l], res[r] = res[r], res[l]
		l++
		r--
	}
	return res
}
// @lc code=end

