package main

import "fmt"

func main2() {
	count := 1
	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)
	for i := 0; i < n-1; i++ {
		if s[i] != s[i+1] {
			count++
		}
	}
	if count < n-1 {
		fmt.Print(count + 2)
	} else {
		fmt.Print(n)
	}
}
