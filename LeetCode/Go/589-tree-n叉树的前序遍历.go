/*
 * @lc app=leetcode.cn id=589 lang=golang
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
func preorder(root *Node) []int {
	res := []int{}

	var pre func(*Node)
	pre = func (root *Node)  {
		if root == nil {
			return
		}
		res = append(res, root.Val)
		for _, child := range root.Children {
			pre(child)
		}
	}

	pre(root)
	return res
}
// @lc code=end

