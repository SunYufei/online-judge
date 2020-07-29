/*
 * @lc app=leetcode.cn id=328 lang=golang
 *
 * [328] 奇偶链表
 */
package leetcode

// @lc code=start
func oddEvenList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	var odd, even = head, head.Next
	var p = even
	for even != nil && even.Next != nil {
		odd.Next = even.Next
		odd = odd.Next
		even.Next = odd.Next
		even = even.Next
	}
	odd.Next = p
	return head
}

// @lc code=end
