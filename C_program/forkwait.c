#include <sys/types.h> 
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/* 부모 프로세스가 자식 프로세스를 생성하고 끝나기를 기다린다. */
int main() 
{
   int pid, child, status;
   printf("[%d] 부모 프로세스 시작 \n", getpid( ));
   pid = fork();        //부모 프로세스 분기
   if (pid == 0) {      //정상적으로 자식 프로세스가 만들어졌다면 0을 리턴
      printf("[%d] 자식 프로세스 시작 \n", getpid( ));  //자식프로세스 시작 출력
      exit(1);
   }
   child = wait(&status); // 자식 프로세스가 끝나기를 기다린다.
   printf("[%d] 자식 프로세스 %d 종료 \n", getpid(), child);
   printf("\t종료 코드 %d\n", status>>8);
}
