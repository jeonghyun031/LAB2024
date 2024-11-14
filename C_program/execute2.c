#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 세 개의 자식 프로세스를 생성하여 각각 다른 명령어를 실행한다. */
int main( ) 
{
   printf("부모 프로세스 시작\n");      // 가장 먼저 출력된다.
   if (fork( ) == 0) {
      execl("/bin/echo", "echo", "hello", NULL);    // 차례대로 hello 출력
      fprintf(stderr,"첫 번째 실패"); 
      exit(1);
   }
      if (fork( ) == 0) {
      execl("/bin/date", "date", NULL);             //날짜 출력
      fprintf(stderr,"두 번째 실패"); 
      exit(2);
  }

   if (fork( ) == 0) {
      execl("/bin/ls","ls", "-l", NULL);        //파일의 상세 정보 출력
      fprintf(stderr,"세 번째 실패"); 
      exit(3);
   }
   printf("부모 프로세스 끝\n");    //자식프로세스가 분기하여 새로운 프로그램을 실행시키는 동안 출력문이 먼저 출력됨
}
