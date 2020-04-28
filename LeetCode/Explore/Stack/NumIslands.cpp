#include "main.h"

class Solution {
  public:
    int numIslands_BFS(vector<vector<char>> &grid) {
        if (grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    ++res;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        int size = q.size();
                        while (size--) {
                            int x = q.front().first, y = q.front().second;
                            if (x + 1 < m && grid[x + 1][y] == '1') {
                                grid[x + 1][y] = '0';
                                q.push({x + 1, y});
                            }
                            if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                                grid[x - 1][y] = '0';
                                q.push({x - 1, y});
                            }
                            if (y + 1 < n && grid[x][y + 1] == '1') {
                                grid[x][y + 1] = '0';
                                q.push({x, y + 1});
                            }
                            if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                                grid[x][y - 1] = '0';
                                q.push({x, y - 1});
                            }
                            q.pop();
                        }
                    }
                }
        return res;
    }
};