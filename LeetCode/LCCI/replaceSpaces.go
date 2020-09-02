package lcci

import "strings"

func replaceSpaces(s string, length int) string {
	var builder strings.Builder
	for i := 0; i < length; i++ {
		if s[i] != ' ' {
			builder.WriteByte(s[i])
		} else {
			builder.WriteString("%20")
		}
	}
	return builder.String()
}
