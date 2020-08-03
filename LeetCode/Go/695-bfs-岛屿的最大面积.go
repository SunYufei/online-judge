/*
 * @lc app=leetcode.cn id=695 lang=golang
 *
 * [695] 岛屿的最大面积
 */
package leetcode

// @lc code=start
func maxAreaOfIsland(grid [][]int) int {
	res := 0
	di := []int{0, 0, 1, -1}
	dj := []int{1, -1, 0, 0}

	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			cur := 0
			qi, qj := []int{i}, []int{j}
			for len(qi) != 0 {
				ci, cj := qi[0], qj[0]
				qi, qj = qi[1:], qj[1:]
				if ci < 0 || cj < 0 || ci >= len(grid) || cj >= len(grid[0]) || grid[ci][cj] == 0 {
					continue
				}
				cur++
				grid[ci][cj] = 0
				for k := 0; k < 4; k++ {
					ni, nj := ci+di[k], cj+dj[k]
					qi = append(qi, ni)
					qj = append(qj, nj)
				}
			}
			if cur > res {
				res = cur
			}
		}
	}

	return res
}

// @lc code=end
