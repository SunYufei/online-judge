/*
 * @lc app=leetcode.cn id=547 lang=golang
 *
 * [547] 朋友圈
 */
package leetcode

// @lc code=start
func findCircleNum(M [][]int) int {
	if len(M) == 0 {
		return 0
	}
	n := len(M)
	count := n
	parent := []int{}
	for i := 0; i < n; i++ {
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
			count--
		}
	}

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if M[i][j] == 1 {
				union(i, j)
			}
		}
	}
	return count
}

// @lc code=end
