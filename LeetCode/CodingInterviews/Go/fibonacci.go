package coding

func fib(n int) int {
	if n < 2 {
		return n
	}
	var a, b = 0, 1
	var res int
	for i := 2; i <= n; i++ {
		res = (a + b) % 1000000007
		a = b
		b = res
	}
	return res
}
