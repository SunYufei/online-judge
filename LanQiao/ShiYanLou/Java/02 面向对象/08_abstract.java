//抽象方法
public abstract class TelePhone {
    public abstract void call();  //抽象方法,打电话
    public abstract void message(); //抽象方法，发短信
}

public class CellPhone extends TelePhone {

    @Override
    public void call() {
        System.out.println("我可以打电话！");
    }

    @Override
    public void message() {
        System.out.println("我可以发短信！");
    }

    public static void main(String[] args) {
        CellPhone cp = new CellPhone();
        cp.call();
        cp.message();
    }

}