#include<iostream>
using namespace std;

struct student5 { int num; };
void fs5(student5& stu)//不希望修改形参的话 写为const student &stu
{
    stu.num = 1010;
}

void fs51(const int i)
{
    //i = 100;//这样不行不能给常量赋值 
}
int main5()
{
    student5 abc;
    abc.num = 100;
    fs5(abc);
    cout << abc.num <<endl;//1010

    //const student5& def = abc;//错误 因为def类型是const& 而函数fs的形参不带const

    //如果形参是const class/type& var  那莫可以传进去一个常量  没有const只能传变量
    return 0;
}