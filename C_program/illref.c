#include <stdio.h>
#include<stdlib.h>

int main() {
    int x, *ptr = NULL;
    x =10;
    ptr = (int*)malloc(sizeof(int));

    if (ptr == NULL) {
        printf("동적 메모리 할당 오류\n");
        exit(1);
    }

    printf("정수 입력>>");
    scanf("%d", ptr);

    printf("1) x = %d, *ptr = %d\n", x, *ptr);
    free(ptr);
    printf("1) x = %d, *ptr = %d\n", x, *ptr);
}