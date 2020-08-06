/*
 * @lc app=leetcode.cn id=146 lang=golang
 *
 * [146] LRU缓存机制
 */
package leetcode

// @lc code=start
type DNode struct {
	key   int
	value int
	prev  *DNode
	next  *DNode
}

type LRUCache struct {
	cache map[int]*DNode

	head *DNode
	tail *DNode

	size     int
	capacity int
}

func Constructor(capacity int) LRUCache {
	lru := LRUCache{
		size:     0,
		capacity: capacity,
		head:     &DNode{key: -1, value: -1},
		tail:     &DNode{key: -1, value: -1},
		cache:    make(map[int]*DNode),
	}
	lru.head.next = lru.tail
	lru.tail.prev = lru.head
	return lru
}

func (lru *LRUCache) addNode(node *DNode) {
	node.prev = lru.head
	node.next = lru.head.next
	lru.head.next.prev = node
	lru.head.next = node
}

func (lru *LRUCache) removeNode(node *DNode) {
	node.prev.next = node.next
	node.next.prev = node.prev
}

func (lru *LRUCache) moveToHead(node *DNode) {
	node.prev.next = node.next
	node.next.prev = node.prev
	lru.addNode(node)
}

func (this *LRUCache) Get(key int) int {
	if _, ok := this.cache[key]; ok {
		this.moveToHead(this.cache[key])
		return this.cache[key].value
	} else {
		return -1
	}
}

func (this *LRUCache) Put(key int, value int) {
	if _, ok := this.cache[key]; ok {
		this.cache[key].value = value
		this.moveToHead(this.cache[key])
	} else {
		node := &DNode{key: key, value: value}
		this.cache[key] = node
		this.addNode(node)
		this.size++
		if this.size > this.capacity {
			k := this.tail.prev.key
			this.removeNode(this.cache[k])
			delete(this.cache, k)
			this.size--
		}
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end
