#include <stdio.h>
int big = 48;
void add (int &a , int &b) {
        big += 10;
        a+=2;
        b+=4;
    }
int main()
{
    printf("2024-12-03, 학번: 21113458 이름: 박정현\n");
    int i =2;
    add(i,big);
    printf("i=%d big=%d\n", i,big);
 
    return 0;
}