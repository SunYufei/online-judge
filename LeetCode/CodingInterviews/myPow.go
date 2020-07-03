package coding

func myPow(x float64, n int) float64 {
	if n < 0 {
		n = -n
		x = 1.0 / x
	}
	var res float64 = 1.0
	for n != 0 {
		if n&1 == 1 {
			res = res * x
		}
		x = x * x
		n = n >> 1
	}
	return res
}
