#include <stdlib.h>
#include <stdio.h>

int main() 
{
   int pid;         //부모프로세스와 똑같은 자식프로세스 복제
   pid = fork();
   if (pid ==0) {   // 자식 프로세스
      printf("[Child] : Hello, world pid=%d\n", getpid());
   }
   else {   // 부모 프로세스
      printf("[Parent] : Hello, world pid=%d\n", getpid());
   }
}
