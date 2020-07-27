/*
 * @lc app=leetcode.cn id=515 lang=golang
 *
 * [515] 在每个树行中找最大值
 */
package leetcode

import "math"

// @lc code=start
func largestValues(root *TreeNode) []int {
	res := []int{}
	q := []*TreeNode{}
	if root != nil {
		q = append(q, root)
	}
	for len(q) != 0 {
		res = append(res, math.MinInt64)
		size := len(q)
		for i := 0; i < size; i++ {
			front := q[0]
			q = q[1:]
			if front.Val > res[len(res)-1] {
				res[len(res)-1] = front.Val
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
