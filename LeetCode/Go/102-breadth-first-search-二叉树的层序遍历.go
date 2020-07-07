/*
 * @lc app=leetcode.cn id=102 lang=golang
 *
 * [102] 二叉树的层序遍历
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
func levelOrder(root *TreeNode) [][]int {
	var res = [][]int{}
	var q = []*TreeNode{}
	if root != nil {
		q = append(q, root)
	}
	for len(q) != 0 {
		var level = make([]int, 0)
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
	return res
}
// @lc code=end

