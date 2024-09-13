public class _Quiz_05 {
    public static void main(String[] args) {
        int [] shoesArray = new int[10];

        for(int i = 0 ; i < shoesArray.length ; i++) {
            shoesArray[i] = 250 + (5 * i);
        }

        for ( int size : shoesArray) {
            System.out.println("사이즈 " + size + " (재고 있음)");
        } 

    int [][] n = { {1} , {1,2,3}, {1}, {1,2,3,4}, {1,2} };
    for(int i =0; i< n.length ; i++) {
        for (int j = 0; j < n[i].length; j++) {
            System.out.print(n[i][j] + " ");
        }
        System.out.print("\n");
    }
    }
}
