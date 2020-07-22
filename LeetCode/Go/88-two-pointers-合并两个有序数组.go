/*
 * @lc app=leetcode.cn id=88 lang=golang
 *
 * [88] 合并两个有序数组
 */
package leetcode

// @lc code=start
func merge(nums1 []int, m int, nums2 []int, n int) {
	var p = m + n - 1
	var i, j = m - 1, n - 1
	for i >= 0 && j >= 0 {
		if nums1[i] > nums2[j] {
			nums1[p] = nums1[i]
			i--
		} else {
			nums1[p] = nums2[j]
			j--
		}
		p--
	}
	for  j >= 0 {
		nums1[p] = nums2[j]
		p--
		j--
	}
}

// @lc code=end
