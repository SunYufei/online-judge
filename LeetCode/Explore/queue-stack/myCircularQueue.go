package stack

// MyCircularQueue struct
type MyCircularQueue struct {
	queue    []int
	front    int
	rear     int
	size     int
	capacity int
}

// Constructor Initialize your data structure here. Set the size of the queue to be k. */
func Constructor(k int) MyCircularQueue {
	return MyCircularQueue{
		queue:    make([]int, k),
		front:    0,
		rear:     0,
		size:     0,
		capacity: k,
	}
}

// EnQueue Insert an element into the circular queue. Return true if the operation is successful. */
func (this *MyCircularQueue) EnQueue(value int) bool {
	if this.IsFull() {
		return false
	}
	this.queue[this.rear] = value
	this.rear = (this.rear + 1 + this.capacity) % this.capacity
	this.size++
	return true
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
func (this *MyCircularQueue) DeQueue() bool {
	if this.IsEmpty() {
		return false
	}
	this.front = (this.front + 1 + this.capacity) % this.capacity
	this.size--
	return true
}

/** Get the front item from the queue. */
func (this *MyCircularQueue) Front() int {
	if this.IsEmpty() {
		return -1
	}
	return this.queue[this.front]
}

/** Get the last item from the queue. */
func (this *MyCircularQueue) Rear() int {
	if this.IsEmpty() {
		return -1
	}
	return this.queue[(this.rear-1+this.capacity)%this.capacity]
}

// IsEmpty Checks whether the circular queue is empty or not. */
func (this *MyCircularQueue) IsEmpty() bool {
	return this.front == this.rear && this.size == 0
}

// IsFull Checks whether the circular queue is full or not. */
func (this *MyCircularQueue) IsFull() bool {
	return this.front == this.rear && this.size == this.capacity
}
