package lcci

func setZeroes(matrix [][]int) {
	m, n := len(matrix), len(matrix[0])
	firstColHasZero, firstRowHasZero := false, false

	for i := 0; i < m; i++ {
		if matrix[i][0] == 0 {
			firstColHasZero = true
		}
	}
	for j := 0; j < n; j++ {
		if matrix[0][j] == 0 {
			firstRowHasZero = true
		}
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[i][j] == 0 {
				matrix[0][j] = 0
				matrix[i][0] = 0
			}
		}
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[0][j] == 0 || matrix[i][0] == 0 {
				matrix[i][j] = 0
			}
		}
	}

	for i := 0; i < m; i++ {
		if firstColHasZero == true {
			matrix[i][0] = 0
		}
	}

	for j := 0; j < n; j++ {
		if firstRowHasZero == true {
			matrix[0][j] = 0
		}
	}
}
