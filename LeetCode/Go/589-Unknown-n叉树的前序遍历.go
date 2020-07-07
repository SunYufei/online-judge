/*
 * @lc app=leetcode.cn id=589 lang=golang
 *
 * [589] N叉树的前序遍历
 */
package leetcode
// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func preorder(root *Node) []int {
	var res = []int{}

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

