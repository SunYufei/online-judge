/*
 * @lc app=leetcode.cn id=590 lang=golang
 *
 * [590] N叉树的后序遍历
 */
package leetcode

// @lc code=start
func postorder(root *Node) []int {
	res := []int{}
	
	var post func(*Node)
	post = func(root *Node){
		if root == nil {
			return
		}
		for _, child := range root.Children {
			post(child)
		}
		res = append(res, root.Val)
	}

	post(root)
	return res
}
// @lc code=end

