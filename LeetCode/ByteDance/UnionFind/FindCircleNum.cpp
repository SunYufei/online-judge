#include <bits/stdc++.h>
using namespace std;

class UnionFind {
  public:
    UnionFind(int n) {
        parent = new int[n + 1];
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        count = n;
    }

    ~UnionFind() { delete[] parent; }

    int find(int p) {
        int root = p;
        while (root != parent[root])
            root = parent[root];
        while (p != parent[p]) {
            int t = p;
            p = parent[p];
            parent[t] = root;
        }
        return root;
    }

    void merge(int p, int q) {
        int rp = find(p);
        int rq = find(q);
        if (rp != rq) {
            parent[rp] = rq;
            --count;
        }
    }

    int getCount() { return count; }

  private:
    int *parent;
    int count;
};

class Solution {
  public:
    int findCircleNum(vector<vector<int>> &M) {
        int n = M.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (M[i][j] == 1)
                    uf.merge(i, j);
        return uf.getCount();
    }
};