import java.util.Scanner;

public class Mian {
        public static void main(String[] args){
            Scanner sc = new Scanner(System.in);

            int won = sc.nextLine();
            double dol = won / 1100;
            System.out.println(won + "원은 " + dol + "입니다.");
        }
}

