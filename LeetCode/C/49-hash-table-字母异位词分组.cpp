/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> mp;
        for (string str : strs) {
            int count[26] = {0};
            for (char c : str)
                ++count[c - 'a'];
            string key;
            for (int i = 0; i < 26; i++)
                key += ('#' + to_string(count[i]));
            mp[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto it = mp.begin(); it != mp.end(); it++)
            res.push_back((*it).second);
        return res;
    }
};
// @lc code=end
