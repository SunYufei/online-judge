/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int myAtoi(string str) {
        int total = 0;
        int sign = 1;
        int p = 0;
        while (p < str.length() && str[p] == ' ')
            ++p;
        if (p == str.length())
            return 0;
        if (str[p] == '+' || str[p] == '-')
            sign = str[p++] == '+' ? 1 : -1;
        while (p < str.length()) {
            int digit = str[p++] - '0';
            if (digit < 0 || digit > 9)
                break;
            if (total > INT_MAX / 10 ||
                total == INT_MAX / 10 && digit > INT_MAX % 10)
                return INT_MAX;
            if (total < INT_MIN / 10 ||
                total == INT_MIN / 10 && digit > -(INT_MIN % 10))
                return INT_MIN;
            total = total * 10 + sign * digit;
        }
        return total;
    }
};
// @lc code=end
