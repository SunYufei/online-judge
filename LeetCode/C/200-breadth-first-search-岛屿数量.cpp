/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    ++res;
                    queue<pair<int, int>> q;
                    grid[i][j] = '0';
                    q.push({i, j});
                    while (!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        if (y + 1 < n && grid[x][y + 1] == '1') {
                            grid[x][y + 1] = '0';
                            q.push({x, y + 1});
                        }
                        if (x + 1 < m && grid[x + 1][y] == '1') {
                            grid[x + 1][y] = '0';
                            q.push({x + 1, y});
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                            grid[x][y - 1] = '0';
                            q.push({x, y - 1});
                        }
                        if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                            grid[x - 1][y] = '0';
                            q.push({x - 1, y});
                        }
                        q.pop();
                    }
                }
        return res;
    }
};
// @lc code=end
