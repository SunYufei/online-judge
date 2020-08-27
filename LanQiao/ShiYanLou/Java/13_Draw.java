public class Draw {
    public static void main(String[] args){
        int num = 2;
        switch(num){
        case 1:
            System.out.println("恭喜你，获得了一等奖");
            break;
        case 2:
            System.out.println("恭喜你，获得了二等奖");
            break;
        case 3:
            System.out.println("恭喜你，获得了三等奖");
            break;
        default:
            System.out.println("很遗憾，下次再来");
        }
    }
}