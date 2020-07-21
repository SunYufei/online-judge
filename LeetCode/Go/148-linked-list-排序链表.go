/*
 * @lc app=leetcode.cn id=148 lang=golang
 *
 * [148] 排序链表
 */
package leetcode

// @lc code=start
func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	// split
	var slow, fast = head, head.Next
	var p *ListNode
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	p = slow
	slow = slow.Next
	p.Next = nil
	// sort
	var left = sortList(head)
	var right = sortList(slow)
	// merge
	var res = &ListNode{}
	p = res
	for left != nil && right != nil {
		if left.Val <= right.Val {
			p.Next = left
			left = left.Next
		} else {
			p.Next = right
			right = right.Next
		}
		p = p.Next
	}
	if left != nil {
		p.Next = left
	} else {
		p.Next = right
	}
	return res.Next
}

// @lc code=end
