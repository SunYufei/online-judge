#include "../main.h"

class Solution {
  public:
    int numSteps(string s) {
        int res = 0, idx = s.size() - 1;
        while (idx > 0) {
            if (s[idx] == '0') {
                --idx;
                ++res;
            } else {
                ++res;
                while (idx >= 0 && s[idx] == '1') {
                    ++res;
                    --idx;
                }
                if (idx > 0)
                    s[idx] = '1';
            }
        }
        return res;
    }
};