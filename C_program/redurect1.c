#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
 /* 표준출력을 파일에 재지정하는 프로그램 */
int main(int argc, char* argv[])
{
    int fd, status;
    fd = open(argv[1], O_CREAT|O_TRUNC|O_WRONLY, 0600);
    dup2(fd, 1); /* 파일을 표준출력에 복제 */
    close(fd);
    printf("Hello stdout !\n");
    fprintf(stderr,"Hello stderr !\n");
}
