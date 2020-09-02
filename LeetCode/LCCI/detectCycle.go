package lcci

func detectCycle(head *ListNode) *ListNode {
	p := head
	set := map[*ListNode]bool{}
	for p != nil {
		if set[p] == true {
			return p
		}
		set[p] = true
		p = p.Next
	}
	return nil
}
