#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void replaceSpace(char *str, int length) {
        string s;
        for (int i = 0; i < length; i++)
            if (str[i] == ' ')
                s += "%20";
            else
                s += str[i];
        for (int i = 0; i < s.length(); i++)
            str[i] = s[i];
    }
};