import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    int n;
        System.out.print("정수 N을 입력하세요 : ");
    n = sc.nextInt();                   //사용자에게 정수 45를 입력받음
        int sum = 0;                    //int형 sum를 선언과 동시에 초기화함
        for (int i = 1; i <= n ; i++)   //1부터 입력받은 N까지 반복
        sum += i;                       //1부터 45까지 더한 값을 sum에 저장함함 
        System.out.print("1부터" +n+ "까지 합 = " + sum);   //최종 더한 값 출력
    }
}