#include <iostream>
using namespace std;

int big(int a, int b) {
    if ( a > b)
        return a;
    else
        return b;
}

char big(char a, char b) {
    if ( a > b)
        return a;
    else
        return b;
}
int main()
{
    int a = 20, b=50;
    char c = 'a' , d='z';
    cout << "big(20,50)의 결과는 " << big(a,b) << endl;
    cout << "big('a','z')의 결과는 " << big(c,d) << endl;
}