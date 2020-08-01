/*
 * @lc app=leetcode.cn id=86 lang=golang
 *
 * [86] 分隔链表
 */
package leetcode

// @lc code=start
func partition(head *ListNode, x int) *ListNode {
	var low, great = &ListNode{}, &ListNode{}
	var p, q = low, great
	for head != nil {
		if head.Val < x {
			p.Next = head
			p = p.Next
		} else {
			q.Next = head
			q = q.Next
		}
		head = head.Next
	}
	q.Next = nil
	p.Next = great.Next
	return low.Next
}

// @lc code=end
