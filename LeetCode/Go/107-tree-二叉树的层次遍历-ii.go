/*
 * @lc app=leetcode.cn id=107 lang=golang
 *
 * [107] 二叉树的层次遍历 II
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
func levelOrderBottom(root *TreeNode) [][]int {
	var res = [][]int{}

	var levelOrder func(*TreeNode, int)
	levelOrder = func(root *TreeNode, level int) {
		if root == nil {
			return
		}
		if level >= len(res) {
			res = append(res, []int{})
		}
		res[level] = append(res[level], root.Val)
		levelOrder(root.Left, level + 1)
		levelOrder(root.Right, level + 1)
	}

	levelOrder(root, 0)
	var l, r = 0, len(res) - 1
	for l < r {
		res[l], res[r] = res[r], res[l]
		l++
		r--
	}
	return res
}
// @lc code=end

