package contest

func calculate(s string) int {
	x, y := 1, 0
	for _, c := range s {
		if c == 'A' {
			x = 2*x + y
		} else if c == 'B' {
			y = 2*y + x
		}
	}
	return x + y
}
