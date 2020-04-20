/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty())
            return matrix;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) {
                    q.push(i, j);
                    seen[i][j] = true;
                }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push(ni, nj);
                    seen[ni][nj] = true;
                }
            }
        }
        return dist;
    }
};
// @lc code=end
