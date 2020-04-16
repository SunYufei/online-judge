/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int numJewelsInStones(string J, string S) {
        bool v[128] = {false};
        for (char c : J)
            v[c] = true;
        int res = 0;
        for (char c : S)
            if (v[c])
                ++res;
        return res;
    }
};
// @lc code=end
