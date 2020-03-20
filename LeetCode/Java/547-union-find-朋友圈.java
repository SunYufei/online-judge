/*
 * @lc app=leetcode.cn id=547 lang=java
 *
 * [547] 朋友圈
 */

// @lc code=start
class Solution {

    class Union {
        private int count;
        private int[] parent;

        public Union(int n) {
            count = n;
            parent = new int[n];
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        private int find(int p) {
            int root = p;
            while (parent[root] != root)
                root = parent[root];
            while (parent[p] != p) {
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

    public int findCircleNum(int[][] M) {
        int n = M.length;
        var union = new Union(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (M[i][j] == 1)
                    union.union(i, j);
        return union.count();
    }
}
// @lc code=end
