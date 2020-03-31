package Bit;

// leetcode 191
class Solution {
    public int hammingWeight(int n) {
        int res = 0;
        while (n != 0) {
            n = n & (n - 1);
            ++res;
        }
        return res;
    }
}