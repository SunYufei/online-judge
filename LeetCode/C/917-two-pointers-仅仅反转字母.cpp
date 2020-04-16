/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    string reverseOnlyLetters(string S) {
        int l = 0, r = S.size() - 1;
        while (l < r) {
            if (!isalpha(S[l]))
                ++l;
            else if (!isalpha(S[r]))
                --r;
            else
                swap(S[l++], S[r--]);
        }
        return S;
    }
};
// @lc code=end
