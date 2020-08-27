public class JudgePrime {
    public static void main(String[] args) {
        int [] ages = {12, 18, 9, 33, 45, 60};
        int i = 1;
        for(int age : ages){
            System.out.println("数组中第" + i + "个元素是" + age);
            i++;
        }
    }
}