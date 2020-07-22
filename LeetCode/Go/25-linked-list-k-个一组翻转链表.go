/*
 * @lc app=leetcode.cn id=25 lang=golang
 *
 * [25] K 个一组翻转链表
 */
package leetcode

// @lc code=start
func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil {
		return nil
	}
	var a, b = head, head
	for i := 0; i < k; i++ {
		if b == nil {
			return head
		}
		b = b.Next
	}
	var newHead = reverse(a, b)
	a.Next = reverseKGroup(b, k)
	return newHead
}

func reverse(a, b *ListNode) *ListNode {
	var pre, cur, t *ListNode = nil, a, nil
	for cur != b {
		t = cur.Next
		cur.Next = pre
		pre = cur
		cur = t
	}
	return pre
}

// @lc code=end
