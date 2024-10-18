#include <stdio.h>

void sub() {
    static int i = 1;
    int k = 1;
    printf("i = %d, k = %d\n", i , k);
    i++; k++;
}

int main() {
    sub();
    sub();
    sub();
}