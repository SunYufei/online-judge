#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        for (int i = 2; i * i < n; i++)
            if (prime[i])
                for (int j = i * i; j < n; j += i)
                    prime[j] = false;
        int res = 0;
        for (int j = 2; j < n; j++)
            if (prime[j])
                ++res;
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.countPrimes(10) << endl;
    cout << sol.countPrimes(20) << endl;
    return 0;
}