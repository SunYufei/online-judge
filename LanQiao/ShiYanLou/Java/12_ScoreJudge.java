public class ScoreJudge {
    public static void main(String[] args){
        int score = 78;
        if(score >= 60){
            if(score >= 80){
                if(score >= 90){
                    System.out.println("成绩优秀");
                }
                else{
                    System.out.println("成绩良好");
                }
            }
            else{
                System.out.println("成绩及格");
            }
        }
        else{
            System.out.println("需要补考");
        }
    }
}