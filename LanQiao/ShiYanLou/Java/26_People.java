public class People {
    // 属性（成员变量） 有什么
    double height;  //身高
    int age;     //年龄
    int sex;    //性别，0为男性，非0为女性

    //无参构造方法
    public People(){

    }
    //有一个参数的构造方法
    public People(int age){

    }

    public People(double h, int a, int s){
        height = h;
        age = a;
        sex = s;
    }

    // 方法 干什么
    void cry(){
        System.out.println("我在哭！");
    }

    void laugh(){
        System.out.println("我在笑！");
    }

    void printBaseMes(){
        System.out.println("我的身高是"+height+"cm");
        System.out.println("我的年龄是"+age+"岁");
        if(this.sex == 0)
            System.out.println("我是男性！");
        else
            System.out.println("我是女性！");

    }
}