// People.java
//外部类People
public class People {
    //定义在外部类中的方法内：
    public void peopleInfo() {
        final String sex = "man";  //外部类方法中的常量
        class Student {
            String ID = "20151234"; //内部类中的常量
            public void print() {
                System.out.println("访问外部类的方法中的常量sex：" + sex);
                System.out.println("访问内部类中的变量ID:" + ID);
            }
        }
        Student a = new Student();  //创建方法内部类的对象
        a.print();//调用内部类的方法
    }
    //定义在外部类中的作用域内
    public void peopleInfo2(boolean b) {
        if(b){
            final String sex = "man";  //外部类方法中的常量
            class Student {
                String ID = "20151234"; //内部类中的常量
                public void print() {
                    System.out.println("访问外部类的方法中的常量sex：" + sex);
                    System.out.println("访问内部类中的变量ID:" + ID);
                }
            }
            Student a = new Student();  //创建方法内部类的对象
            a.print();//调用内部类的方法
        }
    }
    //测试方法内部类
    public static void main(String[] args) {
        People b = new People(); //创建外部类的对象
        System.out.println("定义在方法内：===========");
        b.peopleInfo();  //调用外部类的方法
        System.out.println("定义在作用域内：===========");
        b.peopleInfo2(true);
    }
}