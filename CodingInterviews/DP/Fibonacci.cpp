#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int Fibonacci(int n) {
        if (n < 2)
            return n;
        int ans = 0, a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.Fibonacci(0) << endl;
    cout << sol.Fibonacci(1) << endl;
    cout << sol.Fibonacci(3) << endl;
    return 0;
}