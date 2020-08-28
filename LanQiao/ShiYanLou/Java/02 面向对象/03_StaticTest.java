public class StaticTest{
    public static String string="shiyanlou";
    public static void main(String[] args){
        //静态成员不需要实例化 直接就可以访问
        System.out.println(StaticTest.string);
        //如果不加static关键字 需要这样访问
        StaticTest staticTest=new StaticTest();
        System.out.println(staticTest.string);
        //如果加上static关键字，上面的两种方法都可以使用
    }
}