public class Animal {
    public int legNum;     //动物四肢的数量

    //类方法
    public void bark() {
        System.out.println("动物叫！");
    }
}

public class Dog extends Animal {
}

public class Test{
    public static void main(String[] args) {
        Dog a = new Dog();
        a.legNum = 4;
        a.bark();
    }
}