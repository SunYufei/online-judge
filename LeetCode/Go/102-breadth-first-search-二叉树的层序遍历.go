/*
 * @lc app=leetcode.cn id=102 lang=golang
 *
 * [102] 二叉树的层序遍历
 */
// package leetcode

// @lc code=start
func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}
	res := [][]int{}
	q := []*TreeNode{}
	q = append(q, root)
	for len(q) != 0 {
		level := []int{}
		size := len(q)
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

