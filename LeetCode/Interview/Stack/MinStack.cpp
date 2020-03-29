#include <bits/stdc++.h>
using namespace std;

class MinStack {
  public:
    MinStack() { _min = INT_MAX; }

    void push(int x) {
        _min = min(_min, x);
        _stack.push(make_pair(_min, x));
    }

    void pop() {
        _stack.pop();
        _min = _stack.empty() ? INT_MAX : _stack.top().first;
    }

    int top() { return _stack.top().second; }

    int getMin() { return _stack.top().first; }

  private:
    int _min;
    stack<pair<int, int>> _stack;
};
