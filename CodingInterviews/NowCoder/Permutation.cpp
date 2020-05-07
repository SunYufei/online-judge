#include "main.h"

class Solution {
  public:
    vector<string> Permutation(string str) {
        if (str.empty())
            return {};
        vector<string> res;
        backtrack(str, 0, res);
        sort(res.begin(), res.end());
        return res;
    }

  private:
    void backtrack(string s, int step, vector<string> &res) {
        if (step == s.length() - 1) {
            res.push_back(s);
            return;
        }
        bool exist[128] = {false};
        for (int i = step; i < s.length(); i++) {
            if (exist[s[i]])
                continue;
            exist[s[i]] = true;
            swap(s[i], s[step]);
            backtrack(s, step + 1, res);
            swap(s[i], s[step]);
        }
    }
};