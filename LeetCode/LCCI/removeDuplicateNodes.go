package lcci

func removeDuplicateNodes(head *ListNode) *ListNode {
	res := &ListNode{}
	p := res
	set := make(map[int]bool)
	for head != nil {
		if set[head.Val] == false {
			p.Next = &ListNode{Val: head.Val}
			p = p.Next
		}
		set[head.Val] = true
		head = head.Next
	}
	return res.Next
}
