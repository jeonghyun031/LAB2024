package chap_06;

public class Method {

    public static void sayHello() {             //동사를 사용한 이름
        System.out.println("안녕하세요 메소드입니다.");
    }

    public static void main(String[] args) {
        System.out.println("메소드 호출 전");
        sayHello();
        sayHello();
        sayHello();
        System.out.println("메소드 호출 후");
    }
}
