package coding

func hammingWeight(num uint32) int {
	var res = 0
	for num != 0 {
		res++
		num = num & (num - 1)
	}
	return res
}
