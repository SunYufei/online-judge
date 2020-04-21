#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        int r = grid.size();
        if (r == 0)
            return 0;
        int c = grid[0].size();
        int res = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i, j);
                }
        return res;
    }

    void dfs(vector<vector<char>> &grid, int x, int y) {
        int r = grid.size();
        int c = grid[0].size();
        grid[x][y] = '0';
        if (x - 1 >= 0 && grid[x - 1][y] == '1')
            dfs(grid, x - 1, y);
        if (x + 1 < r && grid[x + 1][y] == '1')
            dfs(grid, x + 1, y);
        if (y - 1 >= 0 && grid[x][y - 1] == '1')
            dfs(grid, x, y - 1);
        if (y + 1 < c && grid[x][y + 1] == '1')
            dfs(grid, x, y + 1);
    }
};