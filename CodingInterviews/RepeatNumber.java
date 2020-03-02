import java.util.HashSet;
import java.util.Set;

public class RepeatNumber {
    public static void main(String[] args) {
        int[] nums = { 2, 3, 1, 0, 2, 5, 3 };
        System.out.println(findRepeatNumber(nums));
    }

    private static int findRepeatNumber(int[] nums) {
        int repeat = -1;
        Set<Integer> set = new HashSet<Integer>();
        for (int num : nums) {
            if (!set.add(num)) {
                repeat = num;
                break;
            }
        }
        return repeat;
    }
}
