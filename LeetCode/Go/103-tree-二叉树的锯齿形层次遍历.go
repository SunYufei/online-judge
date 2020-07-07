/*
 * @lc app=leetcode.cn id=103 lang=golang
 *
 * [103] 二叉树的锯齿形层次遍历
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
func zigzagLevelOrder(root *TreeNode) [][]int {
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
	for i := 0; i < len(res); i++ {
		if i & 1 == 1 {
			var l, r = 0, len(res[i]) - 1
			for l < r {
				res[i][l], res[i][r] = res[i][r], res[i][l]
				l++
				r--
			}
		}
	}
	return res
}
// @lc code=end

