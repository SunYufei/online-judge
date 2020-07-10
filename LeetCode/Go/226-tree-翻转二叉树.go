/*
 * @lc app=leetcode.cn id=226 lang=golang
 *
 * [226] 翻转二叉树
 */
package leetcode

// @lc code=start
func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	root.Left = invertTree(root.Left)
	root.Right = invertTree(root.Right)
	root.Left, root.Right = root.Right, root.Left
	return root
}

// @lc code=end
