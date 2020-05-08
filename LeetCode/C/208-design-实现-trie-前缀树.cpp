/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include "main.h"

// @lc code=start
class Trie {
    bool isEnd;
    unordered_map<char, Trie *> child;

  public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        child.clear();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = this;
        for (char c : word) {
            if (node->child.count(c) == 0)
                node->child[c] = new Trie();
            node = node->child[c];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = this;
        for (char c : word) {
            if (node->child.count(c) == 0)
                return false;
            node = node->child[c];
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        auto node = this;
        for (char c : prefix) {
            if (node->child.count(c) == 0)
                return false;
            node = node->child[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
