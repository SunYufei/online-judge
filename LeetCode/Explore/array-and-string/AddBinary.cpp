#include "../main.h"

class Solution {
  public:
    string addBinary(string a, string b) {
        if (a.empty() || b.empty())
            return a.empty() ? b : a;
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        string res;
        while (i >= 0 || j >= 0 || carry != 0) {
        }
        reverse(res.begin(), res.end());
        return res;
    }
};