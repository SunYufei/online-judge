/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */
#include "main.h"

// @lc code=start
class LRUCache {
  public:
    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.count(key)) {
            moveToHead(cache[key]);
            return cache[key]->value;
        } else
            return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            cache[key]->value = value;
            moveToHead(cache[key]);
        } else {
            auto newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
            ++size;
            if (size > capacity) {
                int k = tail->prev->key;
                removeNode(cache[k]);
                cache.erase(cache.find(k));
                --size;
            }
        }
    }

  private:
    struct Node {
        int key;
        int value;
        Node *prev, *next;
        Node(int k, int v) {
            key = k;
            value = v;
        }
    };

    Node *head, *tail;
    int size, capacity;

    unordered_map<int, Node *> cache;

    void addNode(Node *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    void moveToHead(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        addNode(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
