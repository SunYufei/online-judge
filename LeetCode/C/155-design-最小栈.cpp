/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include "main.h"
// @lc code=start
class MinStack {
  private:
    stack<int> m_stack;
    int m_min;

  public:
    /** initialize your data structure here. */
    MinStack() { m_min = INT_MAX; }

    void push(int x) {
        if (x <= m_min) {
            m_stack.emplace(m_min);
            m_min = x;
        }
        m_stack.emplace(x);
    }

    void pop() {
        int t = m_stack.top();
        m_stack.pop();
        if (t == m_min) {
            m_min = m_stack.top();
            m_stack.pop();
        }
    }

    int top() { return m_stack.top(); }

    int getMin() { return m_min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
