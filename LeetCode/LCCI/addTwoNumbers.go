package lcci

func addTwoNumbers(l1, l2 *ListNode) *ListNode {
	res := &ListNode{}
	p := res
	carry := 0
	for l1 != nil || l2 != nil || carry != 0 {
		if l1 != nil {
			carry += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			carry += l2.Val
			l2 = l2.Next
		}
		p.Next = &ListNode{Val: carry % 10}
		p = p.Next
		carry /= 10
	}
	return res.Next
}
