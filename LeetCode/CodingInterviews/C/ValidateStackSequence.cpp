#include "main.h"

class Solution {
  public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        if (pushed.empty() && popped.empty())
            return true;
        if (pushed.empty() || popped.empty() || pushed.size() != popped.size())
            return false;
        stack<int> s;
        for (int i = 0, j = 0; i < pushed.size(); i++) {
            s.push(pushed[i]);
            while (!s.empty() && s.top() == popped[j]) {
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};