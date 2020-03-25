package Recursion;

class Solution {
    public int lastRemaining(int n, int m) {
        int flag = 0;
        for (int i = 2; i <= n; i++)
            flag = (flag + m) % i;
        return flag;
    }
}