package coding

func findNumberIn2DArray(matrix [][]int, target int) bool {
	var m = len(matrix)
	if m == 0 {
		return false
	}
	var n = len(matrix[0])
	var i, j = 0, n - 1
	for i < m && j >= 0 {
		if matrix[i][j] == target {
			return true
		} else if matrix[i][j] < target {
			i++
		} else {
			j--
		}
	}
	return false
}
