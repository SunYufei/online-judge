import java.util.Arrays;

public class ArraysTest {
    public static void main(String[] args) {
        int[] arr = {6, 17, 92, 32, 58, 22, 84, 66, 36, 33};
        Arrays.sort(arr);
        System.out.println(Arrays.binarySearch(arr, 33));
    }
}