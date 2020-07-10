/*
 * @lc app=leetcode.cn id=236 lang=golang
 *
 * [236] 二叉树的最近公共祖先
 */
package leetcode

// @lc code=start
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	if root == p || root == q {
		return root
	}
	var left = lowestCommonAncestor(root.Left, p, q)
	var right = lowestCommonAncestor(root.Right, p, q)
	if left == nil {
		return right
	}
	if right == nil {
		return left
	}
	if left != nil && right != nil {
		return root
	}
	return nil
}

// @lc code=end
