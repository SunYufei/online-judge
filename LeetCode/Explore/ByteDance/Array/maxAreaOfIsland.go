package array

func maxAreaOfIsland(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}
	m, n := len(grid), len(grid[0])

	var dfs func(int, int) int
	dfs = func(i, j int) int {
		if i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 {
			return 0
		}
		res := 1
		grid[i][j] = 0
		res += dfs(i+1, j)
		res += dfs(i-1, j)
		res += dfs(i, j+1)
		res += dfs(i, j-1)
		return res
	}

	res := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				area := dfs(i, j)
				if area > res {
					res = area
				}
			}
		}
	}
	return res
}
