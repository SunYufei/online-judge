package linklist

func mergeTwoLists(l1, l2 *ListNode) *ListNode {
	var head = &ListNode{}
	var p = head
	for l1 != nil && l2 != nil{
		if l1.Val <= l2.Val {
			p.Next = l1
			l1 = l1.Next
		} else {
			p.Next = l2
			l2 = l2.Next
		}
		p = p.Next
	}
	if l1 != nil {
		p.Next = l1
	} else {
		p.Next = l2
	}
	return head.Next
}