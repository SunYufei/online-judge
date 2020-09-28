package inspur

import "fmt"

func main() {
	num, maxR := 1, 1
	var n int
	fmt.Scanf("%d", &n)

	r := make([]int, n)
	t := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &r[i])
	}

	for i := 0; i < n; i++ {
		t[i] = r[i]
		for j := i + 1; j < n; j++ {
			t[j] = r[j]
			if t[i]+1 == t[j] {
				num++
				t[i] = t[j]
			}
		}
		if num > maxR {
			maxR = num
		}
		num = 1
	}

	fmt.Print(n - maxR)
}
