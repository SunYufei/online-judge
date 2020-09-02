package lcci

func checkPermutation(s1, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	set := [256]int{}
	for _, ch := range s1 {
		set[ch]++
	}
	for _, ch := range s2 {
		if set[ch]--; set[ch] < 0 {
			return false
		}
	}
	return true
}
