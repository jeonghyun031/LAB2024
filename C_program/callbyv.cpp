#include<iostream>
using namespace std;

void swap(int a, int b) {
    int tmp;
    
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int x=2, y=9;
    swap(x,y);
    cout << x << ' ' << y;
}