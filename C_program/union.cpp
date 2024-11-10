#include <iostream>
using namespace std;
int main() {
    typedef union {
        int num;
        char name[10];
        double grade;
    }stu;

    cout << "공용체 stu의 크기 : " << sizeof(stu) << endl;
}