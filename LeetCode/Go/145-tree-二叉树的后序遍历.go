/*
 * @lc app=leetcode.cn id=145 lang=golang
 *
 * [145] 二叉树的后序遍历
 */
// package leetcode

// @lc code=start
func postorderTraversal(root *TreeNode) []int {
	var res = make([]int, 0)

	var post func(*TreeNode)
	post = func(root *TreeNode) {
		if root == nil {
			return
		}
		post(root.Left)
		post(root.Right)
		res = append(res, root.Val)
	}

	return res
}

// @lc code=end
