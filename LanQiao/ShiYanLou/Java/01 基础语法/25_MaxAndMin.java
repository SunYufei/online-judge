import java.util.Arrays;

public class MaxAndMin {
    public static void main(String[] args) {
        int[] data = {313, 89, 123, 323, 313, 15, 90, 56, 39};
        // 方法1
        int max = data[0];
        int min = data[0];
        for (int i = 0; i < data.length; i++) {
            if (data[i] > max) {
                max = data[i];
            }
            if (data[i] < min) {
                min = data[i];
            }
        }
        System.out.println(min);
        System.out.println(max);
        //方法二
        //Arrays.sort(data);
        //System.out.println(data[0]);
        //System.out.println(data[data.length - 1]);
        //方法三
        //System.out.println(Arrays.stream(data).min().getAsInt());
        //System.out.println(Arrays.stream(data).max().getAsInt());
    }
}