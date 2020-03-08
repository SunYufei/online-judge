class Solution {
    public int hammingWeight(int n) {
        int ans = 0;
        while (n != 0) {
            ans += n & 1;
            n >>>= 1;
        }
        return ans;
        // or just one line
        // return Integer.bitCount(n);
    }
}

public class HammingWeight {
    public static void main(String[] args) {
        var sol = new Solution();
        System.out.println(sol.hammingWeight(9));
        System.out.println(sol.hammingWeight(128));
        System.out.println(sol.hammingWeight(129));
    }
}