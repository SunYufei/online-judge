#include "main.h"

class Solution {
  public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<int> res;
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, dir = 0;
        while (x >= 0 && x < m && y >= 0 && y < m && !vis[x][y]) {
            res.push_back(matrix[x][y]);
            vis[x][y] = true;
            while (x + dx[dir] >= 0 && x + dx[dir] < m && y + dy[dir] >= 0 &&
                   y + dy[dir] < n && !vis[x + dx[dir]][y + dy[dir]]) {
                x += dx[dir];
                y += dy[dir];
                res.push_back(matrix[x][y]);
                vis[x][y] = true;
            }
            dir = (dir + 1) % 4;
            x += dx[dir];
            y += dy[dir];
        }
        return res;
    }
};