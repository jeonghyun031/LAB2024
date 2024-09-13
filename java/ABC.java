public class ABC {
    public static void main(String[] args) {
        // String coffees [] = {"아메리카노", "카페모카", "라떼", "카푸치노"};
        // for ( int i = 0; i < 4 ; i++) {
        //     System.out.println(coffees[i] + " 하나");
        // }
        // System.out.println("주세요.");

        // System.out.println("-------------");

        // for ( int i = 0; i < coffees.length ; i++) {
        //     System.out.println(coffees[i] + " 둘");
        // }
        // System.out.println("-------------");
        // for (String drink : coffees) {
        //     System.out.println(drink + " 셋");
        // }
        // for (String drink : coffees) {
        //     System.out.println(drink + "하나");
            
        // }
        // System.out.println("주세요");

    String [][] Array = new String[10][15];
    String[] eng = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    
    for (int i = 0; i < Array.length ; i++) {
        for (int j=0; j < Array[i].length ; j++) {
            Array[i][j] = eng[i] + (j + 1);
        }
    }
    
    for (int i = 0; i < Array.length; i++) {
        for(int j=0; j < Array[i].length ; j++) {
            System.out.print(Array[i][j] + " ");
        }
        System.out.println();
    }
    }
}
