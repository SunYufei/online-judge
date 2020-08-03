// package binsearch

func search(nums []int, target int) int {
	var l, r = 0, len(nums) - 1
	for l <= r {
		var m = l + (r-l)>>1
		if nums[m] == target {
			return m
		} else if nums[m] < target {
			l = m + 1
		} else {
			r = m - 1
		}
	}
	return -1
}
