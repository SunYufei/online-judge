package coding

func constructArr(a []int) []int {
	var b = make([]int, len(a))
	var n, t = len(a), 1
	for i := 0; i < n; i++ {
		b[i] = t
		t *= a[i]
	}
	t = 1
	for i := n - 1; i >= 0; i-- {
		b[i] *= t
		t *= a[i]
	}
	return b
}
