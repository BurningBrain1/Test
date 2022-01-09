#include<iostream>
using namespace std;

int main4()
{

    //1 const char * p
    //p指向的内容不能通过p来修改 p为常量指针
    char str[] = "ILove";
    char* p1;
    p1 = str;
    *p1 = 'Y';//此时p为“YLove”
    p1++; //p可以指向不同的位置 只要这些位置的内存归我们管
    cout << p1 << endl;//此时p为“Love”因为指针向前走了一格

    const char* p;
    //*p = 'Y';//错误
    str[0] = 'Y';//正确

    //2 char const *p等价于const char *p

    //3 char * const p
    //p不可以再指向不同目标 p为指针常量
    char str1[] = "I Love";
    char* const p2 = str1;//定义的时候必须初始化
    //p2++;//不可以 p不可以指向不同目标
    *p2 = 'Y';//但可以修改指向目标中的内容

    //4 const char * const p=str或char const * const p=str 都不可变

    //5 其他用法
    int i = 100;
    const int& a = i;//表示a代表的内容不能通过a自己来修改 所以a=200非法
    const int& b = 156;//可以 字面值初始化常量引用 但int& b=156错误
                       //b看起来是分配了内存 讲左值右值会再提到
    //b = 157;//错误 b看成常量 值不能修改
    return 0;
}