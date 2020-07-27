/*
 * @lc app=leetcode.cn id=515 lang=golang
 *
 * [515] 在每个树行中找最大值
 */
// package leetcode

import "math"

// @lc code=start
func largestValues(root *TreeNode) []int {
	res := []int{}

	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, level int) {
		if root == nil {
			return
		}
		if level >= len(res) {
			res = append(res, math.MinInt64)
		}
		if root.Val > res[level] {
			res[level] = root.Val
		}
		dfs(root.Left, level+1)
		dfs(root.Right, level+1)
	}
	dfs(root, 0)

	return res
}

// @lc code=end
