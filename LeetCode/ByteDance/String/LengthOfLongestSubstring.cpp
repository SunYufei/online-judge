#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0;
        int index[128];
        memset(index, 0, sizeof(index));
        for (int j = 0, i = 0; j < n; j++) {
            i = max(index[s[j]], i);
            ans = max(ans, j - i + 1);
            index[s[j]] = j + 1;
        }
        return ans;
    }
};