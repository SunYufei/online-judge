/*
 * @lc app=leetcode.cn id=143 lang=golang
 *
 * [143] 重排链表
 */
package leetcode

// @lc code=start
func reorderList(head *ListNode) {
	if head == nil || head.Next == nil {
		return
	}
	// split
	var right, p = head, head
	for p != nil && p.Next != nil {
		right = right.Next
		p = p.Next.Next
	}
	p = right
	right = right.Next
	p.Next = nil
	// reverse
	p = nil
	for right != nil {
		var t = right.Next
		right.Next = p
		p = right
		right = t
	}
	right = p
	// insert
	p = head
	for p != nil && right != nil {
		var t = right
		right = right.Next
		t.Next = p.Next
		p.Next = t
		p = t.Next
	}
}

// @lc code=end
