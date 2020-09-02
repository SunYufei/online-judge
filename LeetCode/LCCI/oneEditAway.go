package lcci

import "math"

func oneEditAway(first, second string) bool {
	if first == second {
		return true
	}
	if math.Abs(float64(len(first)-len(second))) > 1 {
		return false
	}
	i, j, k := 0, len(first)-1, len(second)-1
	for i < len(first) && i < len(second) && first[i] == second[i] {
		i++
	}
	for j >= 0 && k >= 0 && first[j] == second[k] {
		j--
		k--
	}
	return j-i < 1 && k-i < 1
}
