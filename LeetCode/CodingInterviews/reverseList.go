package coding

func reverseListTwoPointer(head *ListNode) *ListNode {
	var pre, cur, t *ListNode = nil, head, nil
	for cur != nil {
		t = cur.Next
		cur.Next = pre
		pre = cur
		cur = t
	}
	return pre
}

func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var last = reverseList(head.Next)
	head.Next.Next = head
	head.Next = nil
	return last
}
