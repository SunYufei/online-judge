package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	nums := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}

	maxCount := 1
	for i := 0; i < n; i++ {
		k := nums[i]
		t := 1
		for j := i + 1; j < n; j++ {
			if k+1 == nums[j] {
				t++
				k = nums[j]
			}
		}
		if t > maxCount {
			maxCount = t
		}
	}

	fmt.Print(n - maxCount)
}
