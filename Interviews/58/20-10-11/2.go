package interview

func removeDuplicate(array []int) []int {
	mp := map[int]int{}
	for _, v := range array {
		mp[v]++
	}
	res := []int{}
	for _, v := range array {
		if mp[v] == 1 {
			res = append(res, v)
		} else {
			mp[v]--
		}
	}
	return res
}
