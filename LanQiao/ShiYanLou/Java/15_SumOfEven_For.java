public class SumOfEven {
    public static void main(String[] args){
        int sum = 0;
        for(int i = 1; i <= 1000; i++) {
            if(0 == i % 2) {
                sum += i;
            }
        }
        System.out.println("用for，1到1000中，所有偶数和为：" + sum);
    }
}