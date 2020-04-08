/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int res = 0;
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) {
                int area = 0;
                queue<int> qi, qj;
                qi.push(i);
                qj.push(j);
                while (!qi.empty()) {
                    int ci = qi.front();
                    qi.pop();
                    int cj = qj.front();
                    qj.pop();
                    if (ci < 0 || cj < 0 || ci == grid.size() ||
                        cj == grid[0].size() || grid[ci][cj] == 0)
                        continue;
                    grid[ci][cj] = 0;
                    ++area;
                    for (int k = 0; k < 4; k++) {
                        qi.push(ci + dx[k]);
                        qj.push(cj + dy[k]);
                    }
                }
                res = max(res, area);
            }
        return res;
    }
};
// @lc code=end
