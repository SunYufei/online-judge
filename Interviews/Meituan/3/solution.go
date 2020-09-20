package main

import "fmt"

func main() {
	var n, m int
	fmt.Scanf("%d %d\n", &n, &m)

	var s, t string
	fmt.Scanf("%s\n%s\n", &s, &t)

	res := 0
	i, j := 0, 0
	for i < n && j < m {
		if s[i] == t[j] {
			res += (i + 1)
			i, j = i+1, j+1
		} else {
			i++
		}
	}

	if j != m {
		fmt.Print("No")
	} else {
		fmt.Println("Yes")
		fmt.Print(res)
	}
}
