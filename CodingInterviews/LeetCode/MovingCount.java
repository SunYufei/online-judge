package LeetCode;

import java.util.*;

class Solution {
    boolean[][] vis;

    public int movingCount(int m, int n, int k) {
        vis = new boolean[m][n];
        return dfs(0, 0, m, n, k);
    }

    int dfs(int x, int y, int m, int n, int k) {
        if (add(x, y) > k || x > m - 1 || y > n - 1 || vis[x][y])
            return 0;
        vis[x][y] = true;
        return 1 + dfs(x + 1, y, m, n, k) + dfs(x, y + 1, m, n, k);
    }

    int add(int a, int b) {
        int res = 0;
        while (a != 0) {
            res += a % 10;
            a /= 10;
        }
        while (b != 0) {
            res += b % 10;
            b /= 10;
        }
        return res;
    }

    int movingCountBFS(int m, int n, int k) {
        boolean[][] vis = new boolean[m][n];
        int res = 0;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[] { 0, 0, 0, 0 });
        while (!queue.isEmpty()) {
            int[] x = queue.poll();
            int i = x[0], j = x[1], si = x[2], sj = x[3];
            if (i < 0 || i >= m || j < 0 || j >= n || k < si + sj || vis[i][j])
                continue;
            vis[i][j] = true;
            ++res;
            queue.add(new int[] { i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj });
            queue.add(new int[] { i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8 });
        }
        return res;
    }
}