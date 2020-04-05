/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include "main.h"

// @lc code=start
class UnionFind {
  private:
    int count;
    vector<int> parent;

  public:
    UnionFind(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size();
        count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                } else
                    parent.push_back(-1);
    }

    int find(int p) {
        if (parent[p] != p)
            parent[p] = find(parent[p]);
        return parent[p];
    }

    void merge(int p, int q) {
        int rp = find(p);
        int rq = find(q);
        if (rp != rq) {
            parent[rp] = rq;
            --count;
        }
    }

    int get_count() { return count; }
};

class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        UnionFind uf(grid);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i - 1 >= 0 && grid[i - 1][j] == '1')
                        uf.merge(i * n + j, (i - 1) * n + j);
                    if (i + 1 < m && grid[i + 1][j] == '1')
                        uf.merge(i * n + j, (i + 1) * n + j);
                    if (j - 1 >= 0 && grid[i][j - 1] == '1')
                        uf.merge(i * n + j, i * n + j - 1);
                    if (j + 1 < n && grid[i][j + 1] == '1')
                        uf.merge(i * n + j, i * n + j + 1);
                }
        return uf.get_count();
    }
};
// @lc code=end
