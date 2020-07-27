/*
 * @lc app=leetcode.cn id=653 lang=golang
 *
 * [653] 两数之和 IV - 输入 BST
 */
package leetcode

// @lc code=start
// func findTarget(root *TreeNode, k int) bool {
// 	if root == nil {
// 		return false
// 	}
// 	set := map[int]bool{}
// 	q := []*TreeNode{}
// 	q = append(q, root)
// 	for len(q) != 0 {
// 		t := q[0]
// 		q = q[1:]
// 		if _, ok := set[k-t.Val]; ok {
// 			return true
// 		}
// 		set[t.Val] = true
// 		if t.Left != nil {
// 			q = append(q, t.Left)
// 		}
// 		if t.Right != nil {
// 			q = append(q, t.Right)
// 		}
// 	}
// 	return false
// }
func findTarget(root *TreeNode, k int) bool {
	if root == nil {
		return false
	}
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

	l, r := 0, len(order)-1
	for l < r {
		sum := order[l] + order[r]
		if sum == k {
			return true
		} else if sum < k {
			l++
		} else {
			r--
		}
	}
	return false
}

// @lc code=end
