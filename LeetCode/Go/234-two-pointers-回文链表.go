/*
 * @lc app=leetcode.cn id=234 lang=golang
 *
 * [234] 回文链表
 */
package leetcode

// @lc code=start
func isPalindrome(head *ListNode) bool {
	var slow, fast = head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	if fast != nil {
		slow = slow.Next
	}

	var reverse = func(head *ListNode) *ListNode {
		var p, c, t *ListNode = nil, head, nil
		for c != nil {
			t = c.Next
			c.Next = p
			p = c
			c = t
		}
		return p
	}

	var left, right = head, reverse(slow)
	for right != nil {
		if left.Val != right.Val {
			return false
		}
		left = left.Next
		right = right.Next
	}
	return true
}

// @lc code=end
