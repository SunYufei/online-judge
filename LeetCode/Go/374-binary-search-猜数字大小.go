/*
 * @lc app=leetcode.cn id=374 lang=golang
 *
 * [374] 猜数字大小
 */
// package leetcode

// @lc code=start
// /**
//  * Forward declaration of guess API.
//  * @param  num   your guess
//  * @return 	     -1 if num is lower than the guess number
//  *			      1 if num is higher than the guess number
//  *               otherwise return 0
//  * func guess(num int) int;
//  */

func guessNumber(n int) int {
	var low, high = 1, n
	for low <= high {
		var mid = low + (high-low)>>1
		var res = guess(mid)
		if res == 0 {
			return mid
		} else if res < 0 {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return -1
}

// @lc code=end
