package coding

func getKthFromEnd(head *ListNode, k int) *ListNode {
	var p, res = head, head
	for k > 0 {
		if p == nil {
			return nil
		}
		p = p.Next
		k--
	}
	for p != nil {
		p = p.Next
		res = res.Next
	}
	return res
}
