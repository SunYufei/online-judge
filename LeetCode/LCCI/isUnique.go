package lcci

func isUnique(astr string) bool {
	var mark uint32 = 0
	for _, ch := range astr {
		moveBit := ch - 'a'
		if mark&(1<<moveBit) != 0 {
			return false
		}
		mark |= (1 << moveBit)
	}
	return true
}
