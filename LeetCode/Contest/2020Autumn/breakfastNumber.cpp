#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        int mod = 1e9 + 7;
        vector<int> d(1e6 + 10);
        for (auto i : drinks) {
            ++d[i];
        }
        int sum = 0;
        for (int i = 1; i < d.size(); i++) {
            sum += d[i];
            sum %= mod;
            d[i] = sum;
        }
        int res = 0;
        for (auto i : staple) {
            if (x - i >= 0) {
                res += d[x - i];
                res %= mod;
            }
        }
        return res;
    }
};