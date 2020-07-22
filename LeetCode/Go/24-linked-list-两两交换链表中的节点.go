/*
 * @lc app=leetcode.cn id=24 lang=golang
 *
 * [24] 两两交换链表中的节点
 */
package leetcode

// @lc code=start
func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	pre, cur := head, head.Next
	t := cur.Next
	cur.Next = pre
	pre.Next = swapPairs(t)
	return cur
}

// @lc code=end
