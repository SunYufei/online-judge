/*
 * @lc app=leetcode.cn id=142 lang=golang
 *
 * [142] 环形链表 II
 */
package leetcode

// @lc code=start
func detectCycle(head *ListNode) *ListNode {
	var p = head
	var set = map[*ListNode]bool{}
	for p != nil {
		if _, ok := set[p]; ok {
			return p
		}
		set[p] = true
		p = p.Next
	}
	return nil
}

// @lc code=end
