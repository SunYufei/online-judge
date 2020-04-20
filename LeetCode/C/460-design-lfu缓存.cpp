/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU缓存
 */
#include "main.h"

// @lc code=start
class LFUCache {
  private:
    struct Node {
        int count;
        int time;
        int key;
        int value;
        Node(int c, int t, int k, int v)
            : count(c), time(t), key(k), value(v) {}
        bool operator<(const Node &a) const {
            return count == a.count ? time < a.time : count < a.count;
        }
    };

    int capacity;
    int time;
    unordered_map<int, Node> key_table;
    set<Node> s;

  public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        time = 0;
        key_table.clear();
        s.clear();
    }

    int get(int key) {
        if (capacity == 0)
            return -1;
        auto it = key_table.find(key);
        if (it == key_table.end())
            return -1;
        Node cache = it->second;
        s.erase(cache);
        cache.count += 1;
        cache.time = ++time;
        s.insert(cache);
        it->second = cache;
        return cache.value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            if (key_table.size() == capacity) {
                key_table.erase(s.begin()->key);
                s.erase(s.begin());
            }
            Node cache = Node(1, ++time, key, value);
            key_table.insert({key, cache});
            s.insert(cache);
        } else {
            Node cache = it->second;
            s.erase(cache);
            cache.count += 1;
            cache.time = ++time;
            cache.value = value;
            s.insert(cache);
            it->second = cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
