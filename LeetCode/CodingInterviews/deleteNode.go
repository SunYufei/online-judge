package coding

func deleteNode(head *ListNode, val int) *ListNode {
	if head.Val == val {
		return head.Next
	}
	var pre, cur *ListNode = nil, head
	for cur != nil {
		if cur.Val == val {
			pre.Next = cur.Next
			break
		}
		pre = cur
		cur = cur.Next
	}
	return head
}
