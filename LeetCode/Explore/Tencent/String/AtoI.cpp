#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int myAtoi(string str) {
        int index = 0;
        int total = 0;
        int sign = 1;
        int len = str.length();
        // space
        while (index < len && str[index] == ' ')
            ++index;
        if (index == len)
            return 0;
        // signal
        if (str[index] == '+' || str[index] == '-')
            sign = str[index++] == '+' ? 1 : -1;
        // number
        while (index < len) {
            int digit = str[index++] - '0';
            if (digit < 0 || digit > 9)
                break;
            if (total > INT_MAX / 10 ||
                total == INT_MAX / 10 && digit > INT_MAX % 10)
                return INT_MAX;
            if (total < INT_MIN / 10 ||
                total == INT_MIN / 10 && digit > -(INT_MIN % 10))
                return INT_MIN;
            total = total * 10 + sign * digit;
        }
        return total;
    }
};

int main() {
    Solution sol;
    cout << sol.myAtoi("1") << endl;
    cout << sol.myAtoi("  4 56") << endl;
    return 0;
}