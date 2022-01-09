#include<iostream>
using namespace std;

void func(int& ta, int& tb)//形参类型都是引用类型
{
    ta = 4; //改ta tb值影响main()中的a和b
    tb = 5;
}

int main40()
{
    int value = 10;
    //refval就是引用(类型是引用类型)
    int& refval = value;//value的别名是refval 
    refval = 13;//等价于value=13；

    //int& refval2;//错误 定义引用类型必须初始化
    //int& refval3 = 10;//错误 引用必须绑定到变量或对象上
    int bvalue = 89;
    //float& refvalue = bvalue;//错误 类型要相同

    int a = 3;
    int& b = a;//引用 注意&符号在=的左侧
    int* p = &a;//取地址符 注意&符号在=的右侧

    int a1 = 13;
    int b1 = 14;
    func(a1, b1);
    cout << a1 << " " << b1 << endl;//4 5


    return 0;
}