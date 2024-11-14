#include <stdio.h>
#include <unistd.h>
int main()
{ 
   int pid;
   printf("[%d] 프로세스 시작 \n", getpid());       //프로세스 아이디 출력
   pid = fork();                        //자식 프로세스 생성
   printf("[%d] 프로세스 : 리턴값 %d\n", getpid(), pid);    //자식 프로세스가 완료되었다면 리턴값 0을 반환함
}
