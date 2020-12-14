// package binsearch

func search(nums []int, target int) int {
	var l, r = 0, len(nums) - 1
	for l <= r {
		var m = l + (r-l)>>1
		if nums[m] == target {
			return m
		} else if nums[l] <= nums[m] {
			// left grow
			if nums[l] <= target && target <= nums[m] {
				r = m - 1
			} else {
				l = m + 1
			}
		} else {
			// right grow
			if nums[m] <= target && target <= nums[r] {
				l = m + 1
			} else {
				r = m - 1
			}
		}
	}
	return -1
}
