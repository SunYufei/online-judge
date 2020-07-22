/*
 * @lc app=leetcode.cn id=445 lang=golang
 *
 * [445] 两数相加 II
 */
package leetcode

// @lc code=start
func addTwoNumbersList(l1 *ListNode, l2 *ListNode) *ListNode {
	var s1, s2 []int
	for l1 != nil {
		s1 = append(s1, l1.Val)
		l1 = l1.Next
	}
	for l2 != nil {
		s2 = append(s2, l2.Val)
		l2 = l2.Next
	}
	var carry = 0
	var res *ListNode
	for len(s1) != 0 || len(s2) != 0 || carry != 0 {
		if len(s1) != 0 {
			carry += s1[len(s1)-1]
			s1 = s1[:len(s1)-1]
		}
		if len(s2) != 0 {
			carry += s2[len(s2)-1]
			s2 = s2[:len(s2)-1]
		}
		var node = &ListNode{Val: carry % 10}
		carry /= 10
		node.Next = res
		res = node
	}
	return res
}

// @lc code=end
