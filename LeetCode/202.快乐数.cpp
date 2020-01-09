/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int d[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    bool isHappy(int n) {
        set<int> s;
        while (true) {
            if (n == 1)
                return true;
            if (s.count(n) == 1)
                return false;
            s.insert(n);
            int t = 0;
            while (n) {
                t += d[n % 10];
                n /= 10;
            }
            n = t;
        }
    }
};
