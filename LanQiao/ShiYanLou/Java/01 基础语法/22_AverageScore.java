public class AverageScore {
    public static void main(String[] args) {
        int[] data = {61, 57, 95, 85, 75, 65, 44, 66, 90, 32};
        int sum = 0;
        for (int i = 0; i < data.length; i++) {
            sum += data[i];
        }
        System.out.println("平均成绩：" + sum / data.length);
    }
}