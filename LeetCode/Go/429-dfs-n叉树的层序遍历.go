/*
 * @lc app=leetcode.cn id=429 lang=golang
 *
 * [429] N叉树的层序遍历
 */
package leetcode

// @lc code=start
func levelOrder(root *Node) [][]int {
	if root == nil {
		return nil
	}

	res := [][]int{}
	
	var dfs func(*Node, int)
	dfs = func(root *Node, level int) {
		if root == nil {
			return
		}
		if level >= len(res) {
			res = append(res, []int{})
		}
		res[level] = append(res[level], root.Val)
		for _, child := range root.Children {
			dfs(child, level+1)
		}
	}

	dfs(root, 0)
	return res
}

// @lc code=end
