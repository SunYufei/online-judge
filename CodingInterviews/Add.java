class Solution {
    public int add(int a, int b) {
        while (b != 0) {
            int plus = (a ^ b);
            b = ((a & b) << 1);
            a = plus;
        }
        return a;
    }
}

public class Add {
    public static void main(String[] args) {
        var sol = new Solution();
        System.out.print(sol.add(1, 2));
    }
}