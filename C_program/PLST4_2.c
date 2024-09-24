#include <stdio.h>

int sum(int n) {                    //합을 구하는 int형 sum 함수를 선언
                                    //매개변수 n을 선언
    if (n <= 0)                     //n이 0보다 작으면
        return 0;                   //0을 리턴해줌
    else                            //n이 0보다 크면
        return n + sum(n - 1);      //n과 n-1까지 더한 합을 더함
}

int main() {
    int n, result = 0;
    
    printf("정수를 입력하세요 : ");     //정수를 입력하라고 출력
    scanf("%d",&n);                     //정수 57를 입력함
    
    result = sum(n);                    //int형 result값에 앞서 만든 sum함수 값을 넣어줌
    printf("1부터 %d까지의 합 : %d\n", n, result);  //result 값 출력
}
