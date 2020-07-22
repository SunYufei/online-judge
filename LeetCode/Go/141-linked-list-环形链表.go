/*
 * @lc app=leetcode.cn id=141 lang=golang
 *
 * [141] 环形链表
 */
// package leetcode

// @lc code=start
func hasCycle(head *ListNode) bool {
	nodes := map[*ListNode]bool{}
	p := head
	for p != nil {
		if _, ok := nodes[p]; ok {
			return true
		}
		nodes[p] = true
		p = p.Next
	}
	return false
}

// @lc code=end
