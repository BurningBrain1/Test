#include<iostream>
using namespace std;

int main()
{
    int&& refrightvalue = 3;//把该变量理解成一个int型变量也可以
    
    
    //右值引用用来绑定那些即将销毁/临时的对象上
    int value = 10;
    int refval = value;//refval能绑到左值value上去
    int refval2 = 5;//不可以 能绑到左值上的绑不到右值

    string strtest{"I love China"};
    string& r11{strtest};//可以 左值引用绑定左值
    //string& r2{"I love China"};  不可以 左值引用不能绑定到临时变量上
    const string& r3{"I love China"};//可以 创建一个临时变量 绑定到左值r3上
                                    //const引用不但可以绑定到右值 还可以执行到
                                    //string的隐式类型转换并将所得到的值放到string
                                    //临时变量中
    //string&& r4{strtest};//不可以 右值引用不能绑到左值上去
    string&& r5{"I love China"};//可以 绑定一个临时变量 临时变量内容是I love China
    int i = 10;
    int& ri = i;//可以 左值引用
    //int&& ri2 = i;//不可以 不能将一个右值引用绑定到一个左值上
    //int& ri3 = i * 100;//不可以 左值引用不能往右值上绑 i*100是右值
    const int& ri4 = i * 100;//可以 const引用可以绑定到右值
    int&& ri5 = i * 1000;//可以 乘法结果是右值

    //总结：返回左值引用的函数 连同赋值 下标 解引用和前置递增递减运算符 都是返回
    //左值表达式的例子

    //解引用
    int a = 8;
    int* p = &a;
    (*p) = 5;//相当于a=5
    int& q = (*p);//将左值引用返回到左值表达式 因为(*p)返回的是左值

    //返回非引用类型的函数 连同算数 关系 位及后置递增运算符 都生成右值
    int i = 5;
    (++i) = 20;//i被赋值成20

    int i = 5;
    //(i++) = 20; 语法错误 表达式必须是可修改的左值

    int i = 1;
    int&& r1 = i++;//可以 成功绑定右值 但此后的r1的值和i没关系
    //int& r2 = i++;//错误 左值引用不能绑定右值表达式
    int& r3 = ++i;//可以 r3是i的别名 此后r3的值改变就等于i的值改变
    //int&& r4 = ++i;//错误 右值引用不能绑定左值表达式

    //1 虽然&&r1绑定到了右值 但r1本身是左值
    int& r5=r1;//可以 s说明它是个左值
    //int&& r6 = r1;//不可以 r6是右值引用 但r1是左值

    //2 所有变量都要看成左值
    int i = 5;
    i = i + 1;
    //int&& r111 = i;//错误

    //3 任何函数的形参都是左值

    //4 临时对象都是右值
    return 0;
}