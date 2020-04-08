/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int numTilePossibilities(string tiles) {
        int res = 0;
        int box[26] = {0};
        for (char c : tiles)
            ++box[c - 'A'];
        backtrack(box, res);
        return res;
    }

    void backtrack(int box[], int &res) {
        for (int i = 0; i < 26; i++) {
            if (box[i] <= 0)
                continue;
            --box[i];
            ++res;
            backtrack(box, res);
            ++box[i];
        }
    }
};
// @lc code=end
