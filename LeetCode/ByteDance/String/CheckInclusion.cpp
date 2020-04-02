#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        int s1_map[26];
        memset(s1_map, 0, sizeof(s1_map));
        for (auto c : s1)
            ++s1_map[c - 'a'];
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            int s2_map[26];
            memset(s2_map, 0, sizeof(s2_map));
            for (int j = 0; j < s1.length(); j++)
                ++s2_map[s2[i + j] - 'a'];
            if (match(s1_map, s2_map))
                return true;
        }
        return false;
    }

  private:
    bool match(int s1_map[], int s2_map[]) {
        for (int i = 0; i < 26; i++)
            if (s1_map[i] != s2_map[i])
                return false;
        return true;
    }
};