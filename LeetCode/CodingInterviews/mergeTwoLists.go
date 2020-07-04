package coding

func mergeTwoListsRecurrence(l1 *ListNode, l2 *ListNode) *ListNode {
	var res = new(ListNode)
	var p = res
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
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
	return res.Next
}

func mergeTwoLists(l1, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	var res *ListNode
	if l1.Val < l2.Val {
		res = l1
		l1 = l1.Next
	} else {
		res = l2
		l2 = l2.Next
	}
	res.Next = mergeTwoLists(l1, l2)
	return res
}
