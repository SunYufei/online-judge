package main

import "fmt"

func main() {
	var a, b, c, n int
	fmt.Scanf("%d %d %d %d\n", &a, &b, &c, &n)

	var helper func(int, int) int
	helper = func(i, j int) int {
		if i == 1 && j == 1 {
			return 0
		}
		if i == 1 && j == 2 {
			return a
		}
		if i == 2 && j == 1 {
			return b
		}
		if i == 2 && j == 2 {
			return c
		}
		p, q := 1, 1
		for p < i {
			p *= 2
		}
		p /= 2
		for q < j {
			q *= 2
		}
		q /= 2
		if p == q {
			return helper(i-p, j-q) + c
		} else if p > q {
			return helper(i-p, j) + b
		} else {
			return helper(i, j-q) + a
		}
	}

	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scanf("%d %d\n", &x, &y)
		fmt.Println(helper(x, y) % 1e9)
	}
}
