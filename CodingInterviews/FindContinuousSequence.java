import java.util.ArrayList;

class Solution {
    public int[][] findContinuousSequence(int target) {
        var ans = new ArrayList<int[]>();
        int sum = 0;
        int l = 1, r = 1;

        while (l <= target / 2) {
            if (sum < target)
                sum += r++;
            else if (sum > target)
                sum -= l++;
            else {
                int[] t = new int[r - l];
                for (int k = l; k < r; k++)
                    t[k - l] = k;
                ans.add(t);
                sum -= l++;
            }
        }

        return ans.toArray(new int[ans.size()][]);
    }
}

public class FindContinuousSequence {
    public static void main(String[] args) {
        var sol = new Solution();
        System.out.println(sol.findContinuousSequence(9));
        System.out.println(sol.findContinuousSequence(15));
    }
}
