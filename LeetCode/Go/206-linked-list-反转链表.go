/*
 * @lc app=leetcode.cn id=206 lang=golang
 *
 * [206] 反转链表
 */
package leetcode

// @lc code=start
func reverseList(head *ListNode) *ListNode {
	var pre, cur, t *ListNode = nil, head, nil
	for cur != nil {
		t = cur.Next
		cur.Next = pre
		pre = cur
		cur = t
	}
	return pre
}

// @lc code=end
