package coding

func reversePrint(head *ListNode) []int {
	if head == nil {
		return make([]int, 0)
	}
	var res = reversePrint(head.Next)
	res = append(res, head.Val)
	return res
}

func reversePrintRecurrence(head *ListNode) []int {
	var res = make([]int, 0)
	var p = head
	for p != nil {
		res = append(res, p.Val)
		p = p.Next
	}
	// reverse
	var i, j = 0, len(res) - 1
	for i < j {
		res[i], res[j] = res[j], res[i]
		i++
		j--
	}
	return res
}
