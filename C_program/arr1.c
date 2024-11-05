#include <stdio.h>
int main() {
    int i, a[5];
    
    for (i = 0; i < 5; i++) {
        a[i] = (i+1) * 10;
        printf("%d ", a[i]);
    }
    // int i, a[5] = {10, 20, 30, 40, 50};
    //for (i = 0; i < 5; i++)
    // printf("%d", a[i]);
}