/*
 * @lc app=leetcode.cn id=98 lang=golang
 *
 * [98] 验证二叉搜索树
 */
package leetcode

// @lc code=start
func isValidBST(root *TreeNode) bool {
	order := []int{}

	var inorder func(*TreeNode)
	inorder = func(root *TreeNode) {
		if root == nil {
			return
		}
		inorder(root.Left)
		order = append(order, root.Val)
		inorder(root.Right)
	}

	inorder(root)
	for i := 1; i < len(order); i++ {
		if order[i] <= order[i-1] {
			return false
		}
	}
	return true
}

// @lc code=end
