public class MethodTest {
    public static void main(String[] args){
        methodDemo();
    }
    // 这里要加上 static 关键字 因为静态方法只能调用静态方法
    public static void methodDemo(){
        System.out.println("Hello Shiyanlou");
    }
}