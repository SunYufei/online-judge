/*
 * @lc app=leetcode.cn id=102 lang=golang
 *
 * [102] 二叉树的层序遍历
 */
// package leetcode

// @lc code=start
func levelOrder(root *TreeNode) [][]int {
	var res = make([][]int, 0)

	var level func(*TreeNode, int)
	level = func (root *TreeNode, l int)  {
		if root == nil {
			return
		}
		if l >= len(res) {
			res = append(res, []int{})
		}
		res[l] = append(res[l], root.Val)
		level(root.Left, l + 1)
		level(root.Right, l + 1)
	}

	level(root, 0)
	return res
}
// @lc code=end

