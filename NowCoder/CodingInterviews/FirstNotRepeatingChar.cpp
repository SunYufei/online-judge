#include "main.h"

class Solution {
  public:
    int FirstNotRepeatingChar(string str) {
        int hash[128] = {0};
        for (char c : str)
            ++hash[c];
        for (int i = 0; i < str.length(); i++)
            if (hash[str[i]] == 1)
                return i;
        return -1;
    }
};