#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unist.h>
 /* 부모 프로세스가 자식 프로세스를 생성하고 끝나기를 기다린다. */
int main() 
{
    int pid1, pid2, child, status;
	
    printf("[%d] 부모 프로세스 시작 \n", getpid( ));    //부모 프로세스 아이디 출력
    pid1 = fork();                                  //프로세스 분기
    if (pid1 == 0) {                    //정상적으로 생성
         printf("[%d] 자식 프로세스[1] 시작 \n", getpid( ));    //자식프로세스 아이디 출력
         sleep(1);                          //hold
         printf("[%d] 자식 프로세스[1] 종료 \n", getpid( ));    //자식프로세스 종료
         exit(1);
         }
    pid2 = fork();                          //프로세스 분기
    if (pid2 == 0) {                    //정상적으로 생성
     printf("[%d] 자식 프로세스 #2 시작 \n", getpid( ));    //자식 프로세스 2 시작됐다고 알림
     sleep(2);                          //hold
     printf("[%d] 자식 프로세스 #2 종료 \n", getpid( ));    //자식프로세스 1이 종료된 후 2가 종료됨
     exit(2);
    }
 // 자식 프로세스 #1의 종료를 기다린다.
 child = waitpid(pid1, &status, 0); 
 prisntf("[%d] 자식 프로세스 #1 %d 종료 \n", getpid( ), child);
 printf("\t종료 코드 %d\n", status>>8);
}
