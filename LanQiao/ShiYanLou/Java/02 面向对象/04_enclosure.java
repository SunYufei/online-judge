public class People {
    //属性（成员变量）有什么，前面添加了访问修饰符private
    //变成了私有属性，必须通过方法调用
    private double height;     //身高

    //属性已经封装好了，如果用户需要调用属性
    //必须用getter和setter方法进行调用
    //getter和setter方法需要程序员自己定义
    public double getHeight(){
    //getter 方法命名是get关键字加属性名（属性名首字母大写）
    //getter 方法一般是为了得到属性值
      return height;
    }

    //同理设置我们的setter方法
    //setter 方法命名是set关键字加属性名（首字母大写）
    //setter 方法一般是给属性值赋值，所以有一个参数
    public void setHeight(double newHeight){
      height = newHeight;
    }
}

public class NewObject {

    public static void main(String[] args) {
        People LiLei = new People();    //创建了一个People对象LiLei

        //利用setter方法为属性赋值
        LiLei.setHeight(170.0);

        //利用getter方法取属性值
        System.out.println("LiLei的身高是"+LiLei.getHeight());
    }
}