#include "main.h"

class Solution {
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
            return false;
        stack<int> s;
        for (int i = 0, j = 0; i < pushV.size(); i++) {
            s.push(pushV[i]);
            while (!s.empty() && s.top() == popV[j]) {
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};