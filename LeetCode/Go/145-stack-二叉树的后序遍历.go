/*
 * @lc app=leetcode.cn id=145 lang=golang
 *
 * [145] 二叉树的后序遍历
 */
package leetcode

// @lc code=start
func postorderTraversal(root *TreeNode) []int {
	res := []int{}
	stack := []*TreeNode{}
	var lastVisit *TreeNode
	for root != nil || len(stack) != 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}
		node := stack[len(stack)-1]
		if node.Right == nil || node.Right == lastVisit {
			// pop root after right child
			stack = stack[0 : len(stack)-1]
			res = append(res, node.Val)
			// note cur node
			lastVisit = node
		} else {
			root = node.Right
		}
	}
	return res
}

// @lc code=end
