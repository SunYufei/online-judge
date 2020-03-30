#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int reverse(int x) {
        long total = 0;
        long t = x;
        while (t) {
            total *= 10;
            total += t % 10;
            t /= 10;
            if (total < INT_MIN || total > INT_MAX)
                return 0;
        }
        return (int)total;
    }
};