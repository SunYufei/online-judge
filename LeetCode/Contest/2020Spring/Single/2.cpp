#include "main.h"

class Solution {
  public:
    int numWays(int n, vector<vector<int>> &relation, int k) {
        vector<vector<bool>> path(n, vector<bool>(n, false));
        for (auto r : relation)
            path[r[0]][r[1]] = true;
        int res = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t.second == k) {
                if (t.first == n - 1)
                    ++res;
                continue;
            } else {
                for (int i = 0; i < n; i++)
                    if (path[t.first][i])
                        q.push({i, t.second + 1});
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    // vector<vector<int>> relation = {{0, 2}, {2, 1}, {3, 4}, {2, 3},
    //                                 {1, 4}, {2, 0}, {0, 4}};
    // cout << sol.numWays(5, relation, 3) << endl;
    vector<vector<int>> relation = {{0, 2}, {2, 1}};
    cout << sol.numWays(3, relation, 2) << endl;
    return 0;
}