#include<iostream>
using namespace std;

int main2()
{
    //1 左值引用
    int value = 10;
    int& refval = value;//value的别名是refval &是起标识作用 标识是一个引用
    refval = 13;//等价于value=13;

    //2 const引用(常量引用) 也是左值引用 引用那些不希望改变值的对象
    const int& refval2 = value;
    //refval2 = 18;   //错误 编译器提示：表达式必须是可修改的左值

    //3 右值引用
    int&& refrightvalue = 3;//绑定到一个常量
    refrightvalue = 5;//还可以修改值
    return 0;
}