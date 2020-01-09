/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string s;
        while (x) {
            s += ('0' + x % 10);
            x /= 10;
        }
        string::iterator i, j;
        i = s.begin();
        j = s.end() - 1;
        while (i < j) {
            if (*i != *j)
                return false;
            ++i;
            --j;
        }
        return true;
    }
};
