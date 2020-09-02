package lcci

func canPermutePalindrome(s string) bool {
	var mp = make(map[rune]int)
	for _, c := range s {
		mp[c]++
	}
	count := 0
	for _, v := range mp {
		if v%2 != 0 {
			count++
		}
	}
	return count <= 1
}
