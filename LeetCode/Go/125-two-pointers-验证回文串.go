/*
 * @lc app=leetcode.cn id=125 lang=golang
 *
 * [125] 验证回文串
 */
// package leetcode

// @lc code=start
func isPalindrome(s string) bool {
	var l, r = 0, len(s) - 1
	for l < r {
		for !isalnum(s[l]) && l < r {
			l++
		}
		for !isalnum(s[r]) && l < r {
			r--
		}
		if tolower(s[l]) != tolower(s[r]) {
			return false
		}
		l++
		r--
	}
	return true
}

func isalnum(ch byte) bool {
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')
}

func tolower(ch byte) byte {
	if ch >= 'A' && ch <= 'Z' {
		return ch + 'a' - 'A'
	}
	return ch
}

// @lc code=end
