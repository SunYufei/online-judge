#include "../main.h"

class Solution {
  public:
    int minimumSwitchingTimes(vector<vector<int>> &source,
                              vector<vector<int>> &target) {
        int n = source.size();
        if (n == 0)
            return 0;
        int m = source[0].size();
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                mp[source[i][j]]++;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (mp[target[i][j]] > 0) {
                    mp[target[i][j]]--;
                } else {
                    ans++;
                }
            }
        return ans;
    }
};