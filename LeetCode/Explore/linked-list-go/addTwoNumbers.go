package linklist

func addTwoNumbers(l1, l2 *ListNode) *ListNode {
	var head = &ListNode{}
	var p = head
	var carry = 0
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
		carry /= 10
		p = p.Next
	}
	return head.Next
}
