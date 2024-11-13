#include <iostream>
using namespace std;

int main() {
    typedef struct {
        int num;
        char name[10];
        double grade;
    }stu;
        
    cout << "구조체 stu의 크기 : " << sizeof(stu) << endl;
}