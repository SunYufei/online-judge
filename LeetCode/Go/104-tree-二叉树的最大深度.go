/*
 * @lc app=leetcode.cn id=104 lang=golang
 *
 * [104] 二叉树的最大深度
 */
package leetcode

// @lc code=start
func maxDepth(root *TreeNode) int {
	var max = func(i, j int) int {
		if i > j {
			return i
		} else {
			return j
		}
	}
	
	if root == nil {
		return 0
	}
	return 1 + max(maxDepth(root.Left), maxDepth(root.Right))
}
// @lc code=end
