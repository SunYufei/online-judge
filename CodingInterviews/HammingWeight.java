public class HammingWeight {
    public static void main(String[] args) {
        System.out.println(hammingWeight(9));
        System.out.println(hammingWeight(128));
        System.out.println(hammingWeight(129));
    }

    private static int hammingWeight(int n) {
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