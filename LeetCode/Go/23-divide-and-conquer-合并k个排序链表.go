/*
 * @lc app=leetcode.cn id=23 lang=golang
 *
 * [23] 合并K个排序链表
 */
package leetcode

// @lc code=start
func mergeTwo(l1, l2 *ListNode) *ListNode {
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

func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	} else if len(lists) == 1 {
		return lists[0]
	}
	var first = mergeKLists(lists[0 : len(lists)/2])
	var second = mergeKLists(lists[len(lists)/2:])
	return mergeTwo(first, second)
}

// @lc code=end
