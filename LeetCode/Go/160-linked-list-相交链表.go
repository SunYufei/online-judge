/*
 * @lc app=leetcode.cn id=160 lang=golang
 *
 * [160] 相交链表
 */
package leetcode

// @lc code=start
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}
	var pa, pb = headA, headB
	for pa != pb {
		pa = pa.Next
		pb = pb.Next
		if pa == nil && pb == nil {
			return nil
		}
		if pa == nil {
			pa = headB
		}
		if pb == nil {
			pb = headA
		}
	}
	return pa
}

// @lc code=end
