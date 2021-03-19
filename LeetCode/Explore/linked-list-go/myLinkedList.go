package linklist

// Your MyLinkedList object will be instantiated and called as such:
// obj := Constructor();
// param_1 := obj.Get(index);
// obj.AddAtHead(val);
// obj.AddAtTail(val);
// obj.AddAtIndex(index,val);
// obj.DeleteAtIndex(index);

// DLNode double linked node
type DLNode struct {
	Val  int
	Prev *DLNode
	Next *DLNode
}

// MyLinkedList xxx
type MyLinkedList struct {
	Head *DLNode
	Tail *DLNode
	Len  int
}

// Constructor Initialize your data structure here.
func Constructor() MyLinkedList {
	var list = MyLinkedList{}
	list.Head = &DLNode{}
	list.Tail = &DLNode{}
	list.Head.Next = list.Tail
	list.Tail.Prev = list.Head
	list.Head.Prev = list.Tail
	list.Tail.Next = list.Head
	return list
}

// Get Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
func (list *MyLinkedList) Get(index int) int {
	if index < 0 || index >= list.Len {
		return -1
	}
	var p = list.Head.Next
	for i := 0; i < index; i++ {
		p = p.Next
	}
	return p.Val
}

// AddAtHead Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
func (list *MyLinkedList) AddAtHead(val int) {
	var node = &DLNode{Val: val}
	node.Next = list.Head.Next
	list.Head.Next.Prev = node
	node.Prev = list.Head
	list.Head.Next = node
	list.Len++
}

// AddAtTail Append a node of value val to the last element of the linked list. */
func (list *MyLinkedList) AddAtTail(val int) {
	var node = &DLNode{Val: val}
	node.Prev = list.Tail.Prev
	list.Tail.Prev.Next = node
	node.Next = list.Tail
	list.Tail.Prev = node
	list.Len++
}

// AddAtIndex Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
func (list *MyLinkedList) AddAtIndex(index int, val int) {
	if index == list.Len {
		list.AddAtTail(val)
	} else if index > list.Len {
		return
	} else if index < 0 {
		list.AddAtHead(val)
	} else {
		var p = list.Head.Next
		for i := 0; i < index; i++ {
			p = p.Next
		}
		var node = &DLNode{Val: val}
		node.Next = p
		node.Prev = p.Prev
		p.Prev.Next = node
		p.Prev = node
		list.Len++
	}
}

// DeleteAtIndex Delete the index-th node in the linked list, if the index is valid. */
func (list *MyLinkedList) DeleteAtIndex(index int) {
	if index >= 0 && index < list.Len {
		var p = list.Head.Next
		for i := 0; i < index; i++ {
			p = p.Next
		}
		p.Next.Prev = p.Prev
		p.Prev.Next = p.Next
		list.Len--
	}
}
