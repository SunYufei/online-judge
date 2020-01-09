/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        size_t len = s.length();
        if (len == 0 || len == 1)
            return true;
        size_t i;
        for (i = 0; i < len; i++) {
            char ch = s[i];
            if (ch >= 'A' && ch <= 'Z')
                s[i] = 'a' + ch - 'A';
        }
        size_t left = 0, right = len - 1;
        while (left < right) {
            char l = s[left++];
            char r = s[right--];
            while (!((l >= 'a' && l <= 'z') || (l >= '0' && l <= '9')) &&
                   left < len)
                l = s[left++];
            while (!((r >= 'a' && r <= 'z') || (r >= '0' && r <= '9')) &&
                   right > 0)
                r = s[right--];
            if (((l >= 'a' && l <= 'z') || (l >= '0' && l <= '9')) &&
                ((r >= 'a' && r <= 'z') || (r >= '0' && r <= '9')) && r != l)
                return false;
        }
        return true;
    }
};
