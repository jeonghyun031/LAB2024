public class ASCII {
    public static void main(String[] args) {
        char c = 'a';       //대문자는 65 , 소문자는 97, 숫자(0) 48부터 시작
        System.out.println(c);
        System.out.println((int)c);

        c = 'b';
        System.out.println((c));
        System.out.println((int)c);

        c++;
        System.out.println(c);
        System.out.println((int)c);

        System.out.println("--------------------------------------");

        String [][] Array = new String[3][3];
        char ch = 'A';
        
        for (int i = 0; i < Array.length ; i++) {
            for (int j=0; j < Array[i].length ; j++) {
            Array[i][j] = String.valueOf(ch) + (j + 1);
            }
            ch++;
        }
        for (int i = 0; i < Array.length; i++) {
            for(int j=0; j < Array[i].length ; j++) {
                System.out.print(Array[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("--------------------------------------");
        char [] alpha = { 'a', 'b', 'c'};
        for (char k : alpha) {
            System.out.println(k);
        }
        int sum1=0;
        int sum2=0;
        int sum3=0;
        int sum4=0;

        for (int i = 0; i < 10; i++) sum1+=i;
        System.out.println(sum1);

        for (int i = 9; i > 0; i--) sum2+=i;
        System.out.println(sum2);

        for (int i = 0; i > 10; i++) sum3+=i;
        System.out.println(sum3);

        for (int i = 0; i < 10; sum4+=i, i++)
        System.out.println(sum4);
    }
}