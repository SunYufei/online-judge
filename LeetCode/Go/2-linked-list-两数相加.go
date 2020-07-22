/*
 * @lc app=leetcode.cn id=2 lang=golang
 *
 * [2] 两数相加
 */
package leetcode

// @lc code=start
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var carry = 0
	var res = &ListNode{}
	var p = res
	for l1 != nil || l2 != nil || carry != 0 {
		if l1 != nil {
			carry += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			carry += l2.Val
			l2 = l2.Next
		}
		p.Next = &ListNode{Val: carry % 10}
		carry /= 10
		p = p.Next
	}
	return res.Next
}

// @lc code=end
