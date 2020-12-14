package linklist

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
