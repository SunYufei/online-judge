#include "main.h"

class Solution {
  public:
    string LeftRotateString(string str, int n) {
        if (str.empty())
            return "";
        n %= str.size();
        return str.substr(n) + str.substr(0, n);
    }
};