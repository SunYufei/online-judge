/*
 * @lc app=leetcode.cn id=208 lang=golang
 *
 * [208] 实现 Trie (前缀树)
 */
// package leetcode

// @lc code=start
type Trie struct {
	IsEnd bool
	Links map[rune]*Trie
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{Links: make(map[rune]*Trie)}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	var node = this
	for _, c := range word {
		if _, ok := node.Links[c]; ok == false {
			node.Links[c] = &Trie{Links: make(map[rune]*Trie)}
		}
		node = node.Links[c]
	}
	node.IsEnd = true
}

func (this *Trie) searchPrefix(word string) *Trie {
	var node = this
	for _, c := range word {
		if _, ok := node.Links[c]; ok {
			node = node.Links[c]
		} else {
			return nil
		}
	}
	return node
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	var node = this.searchPrefix(word)
	return node != nil && node.IsEnd
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	return this.searchPrefix(prefix) != nil
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
// @lc code=end
