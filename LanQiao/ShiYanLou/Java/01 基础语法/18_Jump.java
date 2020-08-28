public class Jump{
    public static void main(String[] args) {
        // break 练习
        for(int i = 1; i <= 10; i++) {
            System.out.println("循环第" + i + "次");
            if (0 == i % 3) {
                break;
            }
            if (0 == i % 5) {
                System.out.println("我进来了！");
            }
        }
        // continue练习 打印10以内的所有奇数
        for(int i = 1; i <= 10; i++) {
            if(0 == i % 2) // 判断i是否为偶数
                continue;  // 通过continue结束本次循环
            System.out.println(i);
        }
    }
}