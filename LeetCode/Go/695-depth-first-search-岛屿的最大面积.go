/*
 * @lc app=leetcode.cn id=695 lang=golang
 *
 * [695] 岛屿的最大面积
 */
// package leetcode

// @lc code=start
func maxAreaOfIsland(grid [][]int) int {
	if len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}
	var res = 0
	var m, n = len(grid), len(grid[0])

	var dfs func(int, int) int
	dfs = func(i, j int) int {
		if i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 {
			return 0
		}
		grid[i][j] = 0
		var res = 1
		res += dfs(i+1, j)
		res += dfs(i-1, j)
		res += dfs(i, j+1)
		res += dfs(i, j-1)
		return res
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				res = max(res, dfs(i, j))
			}
		}
	}
	return res
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

// @lc code=end
