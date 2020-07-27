/*
 * @lc app=leetcode.cn id=589 lang=golang
 *
 * [589] N叉树的前序遍历
 */
package leetcode

// @lc code=start
func preorder(root *Node) []int {
	if root == nil {
		return nil
	}
	res := []int{}
	stack := []*Node{}
	stack = append(stack, root)
	for len(stack) != 0 {
		top := stack[len(stack)-1]
		stack = stack[0 : len(stack)-1]
		res = append(res, top.Val)
		for i := len(top.Children) - 1; i >= 0; i-- {
			if top.Children[i] != nil {
				stack = append(stack, top.Children[i])
			}
		}
	}
	return res
}

// @lc code=end
