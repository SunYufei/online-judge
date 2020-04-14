package LeetCode;

class Solution {
    public int sumNums(int n) {
        if ((n > 0) && ((n += sumNums(n - 1)) > 0))
            ;
        return n;
    }
}