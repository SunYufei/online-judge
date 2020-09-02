package lcci

import "strings"

func isFlipedString(s1, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	return strings.Index((s2+s2), s1) != -1
}
