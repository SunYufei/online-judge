#include "main.h"

class Solution {
  public:
    void push(int value) {
        if (value <= m_min) {
            m_stack.emplace(m_min);
            m_min = value;
        }
        m_stack.push(value);
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

    int min() { return m_min; }

  private:
    stack<int> m_stack;
    int m_min = INT_MAX;
};
