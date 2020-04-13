/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int findCircleNum(vector<vector<int>> &M) {
        int n = M.size();
        if (n == 0)
            return 0;
        int count = n;
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        function<int(int)> find = [&](int p) {
            if (parent[p] != p)
                parent[p] = find(parent[p]);
            return parent[p];
        };
        auto merge = [&](int p, int q) {
            int rp = find(p), rq = find(q);
            if (rp != rq) {
                parent[rp] = rq;
                --count;
            }
        };
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (M[i][j] == 1)
                    merge(i, j);
        return count;
    }
};
// @lc code=end
