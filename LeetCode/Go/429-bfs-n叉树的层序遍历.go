/*
 * @lc app=leetcode.cn id=429 lang=golang
 *
 * [429] N叉树的层序遍历
 */
// package leetcode

// @lc code=start
func levelOrder(root *Node) [][]int {
	if root == nil {
		return nil
	}
	res := [][]int{}
	queue := []*Node{}
	queue = append(queue, root)
	for len(queue) != 0 {
		level := []int{}
		size := len(queue)
		for i := 0; i < size; i++ {
			front := queue[0]
			queue = queue[1:]
			level = append(level, front.Val)
			for _, child := range front.Children {
				if child != nil {
					queue = append(queue, child)
				}
			}
		}
		res = append(res, level)
	}
	return res
}

// @lc code=end
