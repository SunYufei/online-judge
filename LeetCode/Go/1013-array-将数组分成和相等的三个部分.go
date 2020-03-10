/*
 * @lc app=leetcode.cn id=1013 lang=golang
 *
 * [1013] 将数组分成和相等的三个部分
 */

// @lc code=start

func sum(nums []int) int {
	var res = 0
	for _, num := range nums {
		res = res + num
	}
	return res
}

func canThreePartsEqualSum(A []int) bool {
	var s = sum(A)
	if s%3 != 0 {
		return false
	}

	var target int = s / 3

	var n = len(A)
	var i = 0
	var cur = 0

	for i < n {
		cur += A[i]
		if cur == target {
			break
		}
		i++
	}

	if cur != target {
		return false
	}

	var j = i + 1
	for j+1 < n {
		cur += A[j]
		if cur == target*2 {
			return true
		}
		j++
	}

	return false
}

// @lc code=end
