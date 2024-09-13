package chap_06;

public class Parameter {
    // public static void Power(int num) {
    //     int result = num * num;
    //     System.out.println(num + " 의 2 승은 " + result);
    // }
    // public static void powerByExp(int number, int exponet ){
    //     int sum = 1;
    //     for (int i=0; i < exponet ; i++) {
    //         sum *= number;
    //     }
    //     System.out.println(number + " 의 " + exponet + " 제곱은 "+ sum);
    // }
    // public static void main(String[] args) {
    //     Power(2);
    //     Power(3);
    //     Power(6);
    //     powerByExp(2, 3);
    //     powerByExp(2, 3);
    //     powerByExp(4, 0);
    // }

    // public static String getNumber() {
    //     String phoneNumber = "02-1234-5678";
    //     return phoneNumber;
    // }
    // public static String getAddress() { 
    //     return "서울광역시 강남구";
    // }
    // public static String getActivity() {
    //     return "볼링장, 탁구장, 노래방";
    // }
    // public static void main(String[] args) {
    //     String contactnumber = getNumber();
    //     System.out.println("호텔 전화번호는 " + contactnumber);

    //     String address = getAddress();
    //     System.out.println("호텔 주소 :" + address);

    //     System.out.println("호텔 액티비티 : " + getActivity());
    // }

    public static void main(String[] args) {
        //전달값과 반환값이 있는 메소드
        int retVal = getpower(3);
        System.out.println(retVal);

        retVal = getpower(5);
        System.out.println(retVal);

        retVal = getPowerByExp(3, 3);
        System.out.println(retVal);

        System.out.println(getPowerByExp(2, 4)); //2*2*2*2 = 16
    }
        public static int getpower(int num) {
            int result = num * num;
            return result;
        }

        public static int getPowerByExp(int number, int exponet) {
            int result = 1;
            for (int i = 0 ; i < exponet ; i++) {
                result *= number;
            }
            return result;

        } 
}
