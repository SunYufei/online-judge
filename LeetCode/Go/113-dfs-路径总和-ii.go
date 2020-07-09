/*
 * @lc app=leetcode.cn id=113 lang=golang
 *
 * [113] 路径总和 II
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
func pathSum(root *TreeNode, sum int) [][]int {
	var res = [][]int{}
	var path = []int{}

	var dfs func(*TreeNode, int, []int)
	dfs = func(root *TreeNode, sum int, path []int) {
		if root == nil {
			return
		}
		path = append(path, root.Val)
		if root.Val == sum && root.Left == nil && root.Right == nil {
			var t = make([]int, len(path))
			copy(t, path)
			res = append(res, t)
		}
		dfs(root.Left, sum - root.Val, path)
		dfs(root.Right, sum - root.Val, path)
	}

	dfs(root, sum, path)
	return res
}
// @lc code=end
