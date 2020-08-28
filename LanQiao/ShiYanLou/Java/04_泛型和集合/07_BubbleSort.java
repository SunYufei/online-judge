import java.util.Arrays;

public class BubbleSort {
    public static void sort(int[] arr) {
        for (int i = 0; i < arr.length-1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                //如果当前元素比后一位元素大 交换位置
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] ints = {5, 3, 4, 1, 2};
        sort(ints);
        System.out.println(Arrays.toString(ints));
    }
}