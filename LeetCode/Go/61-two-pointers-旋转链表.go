/*
 * @lc app=leetcode.cn id=61 lang=golang
 *
 * [61] 旋转链表
 */
package leetcode

// @lc code=start
func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || k == 0 {
		return head
	}
	var n, p = 1, head
	for p.Next != nil {
		p = p.Next
		n++
	}
	p.Next = head
	k %= n
	for i := 0; i < n-k; i++ {
		p = p.Next
	}
	head, p.Next = p.Next, nil
	return head
}

// @lc code=end
