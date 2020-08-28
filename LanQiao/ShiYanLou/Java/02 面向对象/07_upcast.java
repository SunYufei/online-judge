class Animal {
    //父类方法
    public void bark() {
        System.out.println("动物叫！");
    }
}

class Dog extends Animal {

    //子类重写父类的bark方法
    public void bark() {
        System.out.println("汪、汪、汪！");
    }
    //子类自己的方法
    public void dogType() {
        System.out.println("这是什么品种的狗？");
    }
}


public class Test {

    public static void main(String[] args) {
        Animal a = new Animal();
        Animal b = new Dog();
        Dog d = new Dog();

        a.bark();
        b.bark();
        //b.dogType();
        //b.dogType()编译不通过
        d.bark();
        d.dogType();
    }

}