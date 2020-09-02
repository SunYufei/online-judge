package lcci

func kthToLast(head *ListNode, k int) int {
	p, q := head, head
	for i := 0; i < k; i++ {
		q = q.Next
	}
	for q != nil {
		p = p.Next
		q = q.Next
	}
	return p.Val
}
