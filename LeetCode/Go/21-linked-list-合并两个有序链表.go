/*
 * @lc app=leetcode.cn id=21 lang=golang
 *
 * [21] 合并两个有序链表
 */

package leetcode

// @lc code=start
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var head = &ListNode{}
	var p, t *ListNode = head, nil
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			t = l1
			l1 = l1.Next
		} else {
			t = l2
			l2 = l2.Next
		}
		t.Next = p.Next
		p.Next = t
		p = p.Next
	}
	if l1 != nil {
		p.Next = l1
	} else {
		p.Next = l2
	}
	return head.Next
}

// @lc code=end
