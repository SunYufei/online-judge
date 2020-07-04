package coding

func verifyPostorder(postorder []int) bool {
	if len(postorder) == 0 {
		return true
	}
	var check=func(left,right int)bool{
		if left>right{
			return true
		}
		var root=postorder[right]
		var k=left
		for k<right && post[k]<root{
			k++
		}
		for i:=k;i<right;i++{
			if postorder[i]<root{
				return false
			}
		}
		if check(left,k-1)==false{
			return false
		}
		if check(k,right-1)==false{
			return false
		}
		return true
	}
	return check(0,len(postorder)-1)
}
