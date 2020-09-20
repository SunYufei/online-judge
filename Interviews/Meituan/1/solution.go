package main

import "fmt"

func main() {
	var m, n int
	fmt.Scanf("%d%d", &m, &n)

	res := 0
	t := m
	for t <= n {
		mp := make(map[int]bool)

		a := t / 100000
		if a == 0 {
			t += (100000 - t%100000)
			continue
		}
		mp[a] = true
		b := (t / 10000) % 10
		if mp[b] == true {
			t += (10000 - t%10000)
			continue
		}
		mp[b] = true
		t1 := a*10 + b

		c := (t / 1000) % 10
		if mp[c] == true {
			t += (1000 - t%1000)
			continue
		}
		mp[c] = true
		d := (t / 100) % 10
		if mp[d] == true {
			t += (100 - t%100)
			continue
		}
		mp[d] = true
		t2 := c*10 + d

		e := (t / 10) % 10
		if mp[e] == true {
			t += (10 - t%10)
			continue
		}
		mp[e] = true
		f := t % 10
		if mp[f] == true {
			t++
			continue
		}
		t3 := e*10 + f

		if t1+t2 == t3 {
			res++
		}
		t++
	}
	fmt.Print(res)
}
