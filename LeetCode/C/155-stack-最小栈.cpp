/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include "main.h"

// @lc code=start
class MinStack {
  private:
    stack<int> s1, s2;

  public:
    MinStack() { s2.push(INT_MAX); }

    void push(int x) {
        s1.emplace(x);
        s2.emplace(x < s2.top() ? x : s2.top());
    }

    void pop() {
        s1.pop();
        s2.pop();
    }

    int top() { return s1.top(); }

    int getMin() { return s2.top(); }
};

// @lc code=end
