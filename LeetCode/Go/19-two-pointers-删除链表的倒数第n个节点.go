/*
 * @lc app=leetcode.cn id=19 lang=golang
 *
 * [19] 删除链表的倒数第N个节点
 */
package leetcode

// @lc code=start
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	var p, pre, cur *ListNode = head, nil, head
	for ; n > 0; n-- {
		p = p.Next
	}
	for p != nil {
		pre = cur
		cur = cur.Next
		p = p.Next
	}
	if pre != nil {
		pre.Next = cur.Next
	} else {
		head = head.Next
	}
	return head
}

// @lc code=end
