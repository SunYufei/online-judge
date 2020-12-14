#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int size = s.size();
        int count1[26] = {0};
        int count2[26] = {0};
        for (int i = 0; i < size; i++)
            ++count1[s[i] - 'a'];
        for (int i = 0; i < size; i++) {
            ++count2[t[i] - 'a'];
            if (count2[t[i] - 'a'] > count1[t[i] - 'a'])
                return false;
        }
        return true;
    }
};