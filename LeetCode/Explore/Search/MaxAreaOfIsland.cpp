#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    res = max(res, dfs(grid, i, j));
        return res;
    }

  private:
    int dfs(vector<vector<int>> &grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ||
            grid[x][y] == 0)
            return 0;
        grid[x][y] = 0;
        int area = 1;
        area += dfs(grid, x + 1, y);
        area += dfs(grid, x - 1, y);
        area += dfs(grid, x, y + 1);
        area += dfs(grid, x, y - 1);
        return area;
    }
};