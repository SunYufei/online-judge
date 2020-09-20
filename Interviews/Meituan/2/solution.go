package main

import "fmt"

func main() {
	var n, m, p, q int
	fmt.Scanf("%d %d %d %d\n", &n, &m, &p, &q)

	mat := [][]rune{}
	for i := 0; i < n; i++ {
		var t string
		fmt.Scanf("%s\n", &t)
		line := []rune{}
		for _, c := range t {
			line = append(line, c)
		}
		mat = append(mat, line)
	}
	var route string
	fmt.Scanf("%s", &route)

	res := 0
	x, y := 0, 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if mat[i][j] == 'S' {
				x, y = i, j
			}
		}
	}
	for _, c := range route {
		if c == 'W' && x-1 >= 0 {
			switch mat[x-1][y] {
			case 'O':
				res += p
				mat[x-1][y] = '+'
				x--
			case 'X':
				res -= q
				mat[x-1][y] = '+'
				x--
			case '+':
				x--
			}
		} else if c == 'S' && x+1 < n {
			switch mat[x+1][y] {
			case 'O':
				res += p
				mat[x+1][y] = '+'
				x++
			case 'X':
				res -= q
				mat[x+1][y] = '+'
				x++
			case '+':
				x++
			}
		} else if c == 'A' && y-1 >= 0 {
			switch mat[x][y-1] {
			case 'O':
				res += p
				mat[x][y-1] = '+'
				y--
			case 'X':
				res -= q
				mat[x][y-1] = '+'
				y--
			case '+':
				y--
			}
		} else if c == 'D' && y+1 < n {
			switch mat[x][y+1] {
			case 'O':
				res += p
				mat[x][y+1] = '+'
				y++
			case 'X':
				res -= q
				mat[x][y+1] = '+'
				y++
			case '+':
				y++
			}
		}
	}

	fmt.Print(res)
}
