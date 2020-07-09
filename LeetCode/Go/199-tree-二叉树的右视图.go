/*
 * @lc app=leetcode.cn id=199 lang=golang
 *
 * [199] 二叉树的右视图
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
func rightSideView(root *TreeNode) []int {
	var res = []int{}
	var q = []*TreeNode{}
	if root != nil {
		q = append(q, root)
	}
	for len(q) != 0 {
		var size = len(q)
		for i := 0; i < size; i++ {
			var front = q[0]
			q = q[1:]
			if i == size - 1 {
				res = append(res, front.Val)
			}
			if front.Left != nil {
				q = append(q, front.Left)
			}
			if front.Right != nil {
				q = append(q, front.Right)
			}
		}
	}	
	return res
}
// @lc code=end

