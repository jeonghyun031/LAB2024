// 1부터 n까지의 합(반복구조)

#include <stdio.h>
int main() {
    int n, sum = 0;
    
    printf("정수를 입력하세요 : ");     //정수를 입력하세요
    scanf("%d",&n);                     //사용자에게 정수를 입력받음
    
    for(int i = 1; i <= n ; i++) {      //사용자에게 입력받은 정수만큼 반복
        sum = sum + i;                  //int형 sum에 값을 더함
    }
    
    printf("1부터 %d까지의 합 : %d", n , sum);  //최종 출력된 값을 보여줌
}