/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */
#include "main.h"

// @lc code=start
class UnionFind {
  private:
    vector<int> parent;
    int count;

    int find(int p) {
        if (parent[p] != p)
            parent[p] = find(parent[p]);
        return parent[p];
    }

  public:
    UnionFind(int n) {
        count = n;
        for (int i = 0; i < n; i++)
            parent.push_back(i);
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
    int findCircleNum(vector<vector<int>> &M) {
        int n = M.size();
        if (n == 0)
            return 0;
        UnionFind uf(n);
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (M[i][j] == 1)
                    uf.merge(i, j);
        return uf.get_count();
    }
};
// @lc code=end
