public class SumOfEven {
    public static void main(String[] args){
        int i1 = 1, i2 = 1;
        int sum1 = 0, sum2 = 0;

        while (i1 <= 1000){     // 循环1000次
            if(0 == i1 % 2) {   // 判断是否为偶数
                sum1 += i1;     // 将偶数加入到总数里
            }
            i1++;               // i自增1
        }
        System.out.println("用while，1到1000中，所有偶数的和为：" + sum1);

        do {
            if (0 == i2 % 2) {  //在条件语句中，将数值写在前面是为了防止将==写成了=
                sum2 += i2;
            }
            i2++;
        } while(i2 <= 1000);
        System.out.println("用do-while，1到1000中，所有偶数的和为：" + sum2);
    }
}