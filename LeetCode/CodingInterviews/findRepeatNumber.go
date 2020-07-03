package coding

import "math"

func findRepeatNumber(nums []int) int {
	for i := range nums {
		for nums[i] != i {
			var t = nums[i]
			if t == nums[t] {
				return t
			}
			nums[i] = nums[t]
			nums[t] = t
		}
	}
	return math.MaxInt64
}

func findRepeatNumberHash(nums []int) int {
	var m = make(map[int]bool)
	for _, v := range nums {
		if _, ok := m[v]; ok {
			return v
		}
		m[v] = true
	}
	return math.MaxInt64
}
