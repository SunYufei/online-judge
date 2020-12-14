package coding

import "strings"

func replaceSpace(s string) string {
	var builder strings.Builder
	for _, c := range s {
		if c == ' ' {
			builder.WriteString("%20")
		} else {
			builder.WriteRune(c)
		}
	}
	return builder.String()
}