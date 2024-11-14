#include <stdlib.h>
#include <stdio.h>
/* 부모 프로세스가 두 개의 자식 프로세스를 생성한다. */
int main() 
{
   int pid1, pid2;
   pid1 = fork();       //pid1이라는 자식 프로세스 복제
   if (pid1 == 0) {     //정상적으로 만들어졌다면 리턴값 0
      printf("[Child 1] : Hello, world ! pid=%d\n", getpid());  //hello world 출력
      exit(0);
   }
   pid2 = fork();       //pid2이라는 자식 프로세스 복제
   if (pid2 == 0) {     //정상적으로 만들어졌다면 리턴값 0
      printf("[Child 2] : Hello, world ! pid=%d\n", getpid());  //hello world 출력하지만 pid1보다는 느림
      exit(0);
   }
   printf("[PARENT] : Hello, world ! pid=%d\n",getpid());       //부모프로세스가 먼저 hello world를 출력함
}
