/*
 * @lc app=leetcode.cn id=141 lang=golang
 *
 * [141] 环形链表
 */
package leetcode

// @lc code=start
func hasCycle(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return false
	}
	var slow, fast = head, head.Next
	for fast != nil && fast.Next != nil {
		if slow == fast {
			return true
		}
		slow = slow.Next
		fast = fast.Next.Next
	}
	return false
}

// @lc code=end
