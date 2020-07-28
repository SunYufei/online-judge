package coding

func reversePairs(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	return mergeSort(nums, 0, len(nums)-1)
}

func mergeSort(nums []int, l, r int) int {
	if l >= r {
		return 0
	}
	var m = l + (r-l)>>1
	var count = mergeSort(nums, l, m) + mergeSort(nums, m+1, r)
	var cache = make([]int, r-l+1)
	var i, t, c = l, l, 0
	for j := m + 1; j <= r; j, c = j+1, c+1 {
		for i <= m && nums[i] <= nums[j] {
			i++
		}
		for t <= m && nums[t] < nums[j] {
			cache[c] = nums[t]
			c, t = c+1, t+1
		}
		cache[c] = nums[j]
		count += m - i + 1
	}
	for t <= m {
		cache[c] = nums[t]
		c, t = c+1, t+1
	}
	for c, t = 0, l; c < r-l+1; c, t = c+1, t+1 {
		nums[t] = cache[c]
	}
	return count
}
