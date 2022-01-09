#include <iostream>
using namespace std;


struct student 
{
    int number;
    char name[100];
    void func() {};
};

int main()
{
    student student1;//定义结构变量 这里可以省略struct 直接用结构名 但C语言不能省略
    student1.number = 1001;
    strcpy_s(student1.name, sizeof(student1.name), "zhangsan");
    student1.func();//调用成员函数

    student* pstudent1 = &student1;
    pstudent1->number = 1005;
    cout << student1.number <<endl;//1005
    return 0;
}