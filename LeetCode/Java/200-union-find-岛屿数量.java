/*
 * @lc app=leetcode.cn id=200 lang=java
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {

    class UnionFind {
        private int count;
        private int[] parent;

        public UnionFind(char[][] grid, int m, int n) {
            count = 0;
            parent = new int[m * n];
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (grid[i][j] == '1') {
                        parent[i * n + j] = i * n + j;
                        ++count;
                    }
        }

        private int find(int p) {
            int root = p;
            while (parent[root] != root)
                root = parent[root];
            while (parent[p] != root) {
                int t = p;
                p = parent[p];
                parent[t] = root;
            }
            return root;
        }

        public void union(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ)
                return;
            parent[rootP] = rootQ;
            --count;
        }

        public int count() {
            return count;
        }
    }

    public int numIslands(char[][] grid) {
        int m = grid.length;
        if (m == 0)
            return 0;
        int n = grid[0].length;
        var unionFind = new UnionFind(grid, m, n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    if (i - 1 >= 0 && grid[i - 1][j] == '1')
                        unionFind.union(i * n + j, (i - 1) * n + j);
                    if (i + 1 < m && grid[i + 1][j] == '1')
                        unionFind.union(i * n + j, (i + 1) * n + j);
                    if (j - 1 >= 0 && grid[i][j - 1] == '1')
                        unionFind.union(i * n + j, i * n + j - 1);
                    if (j + 1 < n && grid[i][j + 1] == '1')
                        unionFind.union(i * n + j, i * n + j + 1);
                }
        return unionFind.count();
    }
}
// @lc code=end
