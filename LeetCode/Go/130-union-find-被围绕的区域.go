/*
 * @lc app=leetcode.cn id=130 lang=golang
 *
 * [130] 被围绕的区域
 */
package leetcode

// @lc code=start
func solve(board [][]byte) {
	if len(board) == 0 || len(board[0]) == 0 {
		return
	}
	r, c := len(board), len(board[0])

	parent := []int{}
	for i := 0; i <= r*c; i++ {
		parent = append(parent, i)
	}

	var find func(int) int
	find = func(p int) int {
		if parent[p] != p {
			parent[p] = find(parent[p])
		}
		return parent[p]
	}

	union := func(p, q int) {
		rp, rq := find(p), find(q)
		if rp != rq {
			parent[rp] = rq
		}
	}

	isConnected := func(p, q int) bool {
		return find(p) == find(q)
	}

	dummy := r * c
	node := func(i, j int) int {
		return i*c + j
	}

	for i := 0; i < r; i++ {
		for j := 0; j < c; j++ {
			if board[i][j] == 'O' {
				if i == 0 || i == r-1 || j == 0 || j == c-1 {
					union(node(i, j), dummy)
				} else {
					if i > 0 && board[i-1][j] == 'O' {
						union(node(i, j), node(i-1, j))
					}
					if i < r-1 && board[i+1][j] == 'O' {
						union(node(i, j), node(i+1, j))
					}
					if j > 0 && board[i][j-1] == 'O' {
						union(node(i, j), node(i, j-1))
					}
					if j < c-1 && board[i][j+1] == 'O' {
						union(node(i, j), node(i, j+1))
					}
				}
			}
		}
	}

	for i := 0; i < r; i++ {
		for j := 0; j < c; j++ {
			if isConnected(node(i, j), dummy) {
				board[i][j] = 'O'
			} else {
				board[i][j] = 'X'
			}
		}
	}
}
// @lc code=end
