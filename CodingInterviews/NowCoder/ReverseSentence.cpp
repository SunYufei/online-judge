#include "main.h"

class Solution {
  public:
    string ReverseSentence(string str) {
        if (str.empty())
            return "";
        reverse(str.begin(), str.end());
        for (int p = 0, c = 0; c <= str.size(); c++)
            if (str[c] == ' ' || c == str.size()) {
                reverse(str.begin() + p, str.begin() + c);
                p = c + 1;
            }
        return str;
    }
};