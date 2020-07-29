package linklist

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || k == 0 {
		return head
	}
	var n, p = 1, head
	for p.Next != nil {
		p = p.Next
		n++
	}
	p.Next = head
	k %= n
	for i := 0; i < n-k; i++ {
		p = p.Next
	}
	head, p.Next = p.Next, nil
	return head
}
