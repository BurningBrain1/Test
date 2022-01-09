// STL.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <array>
#include <string>
#include <vector>
using namespace std;

class A
{
public:
    int m_i;
    A(int tmpv) :m_i(tmpv)
    {
        cout << "A::A()构造函数执行" << endl;
    }
    A(const A& tmpA)
    {
        m_i = tmpA.m_i;
        cout << "A::A()拷贝构造函数执行" << endl;
    }
    ~A()
    {
        cout << "A::~A()析构函数执行" << endl;
    }
};
int main()
{
    //19.2.2 容器的说明和简单应用
    array<string, 5>mystring = {"I","Love1","China"};//定义包含5个string元素
    cout << "mystring.size()=" << mystring.size() << endl;//5
    mystring[0] = "It is long~~~~~~~~~~~~~~~long~~~~~~~long";
    mystring[4] = "It is long~~~~~~~~~~~~~~~long~~~~~~~long";
    cout << "sizeof(string)=" << sizeof(string) << endl;
    for (size_t i = 0; i < mystring.size(); ++i)
    {
        const char* p = mystring[i].c_str();
        cout << "----------------begin------------------------" << endl;
        cout << "数组元素值=" << p << endl;//用下标访问 从0开始
        printf("对象地址=%p\n", &mystring[i]);
        printf("指向的字符串地址=%p\n", p);
        cout << "------------------end--------------------------" << endl;
    }

    const char* p1 = "Love1Love2Love3";
    const char* p2 = "Love1Love2Love3";
    printf("指向字符串的p1地址=%p1\n", p1);
    printf("指向字符串的p2地址=%p2\n", p2);
    cout << "我的妈呀" << endl;

    //mystring.size();
    //sizeof(string) = 28; string类型默认为28字节
    //-----------begin-------------------
    //数组元素值=It is long~~~~~~~~~~~~~~~long~~~~~~~long;
    //对象地址=0057FBF8
    //指向的字符串地址=0078CE58
    //-----------end---------------------
    //-----------begin-------------------
    //数组元素值 = Love1Love2;
    //对象地址=0057FC14
    //指向的字符串地址=00785958
    //-----------end---------------------
    //-----------begin-------------------
    //数组元素值=China
    //对象地址=0057FC30
    //指向的对象地址=0057FC34
    //-----------end---------------------
    //-----------begin-------------------
    //数组元素值=
    //对象地址=0057FC4C
    //指向的对象地址=0057FC50
    //-----------end---------------------
    //-----------begin-------------------
    //数组元素值=It is long~~~~~~~~~~~~~~~long~~~~~~~long
    //对象地址=0057FC68
    //指向的对象地址=0078D0D0
    //-----------end---------------------
    //指向字符串的p1地址=00EAED542
    //指向字符串的p2地址=00EAED542

    vector<A>myveca;
    cout << "myveca.capacity()=" << myveca.capacity() << endl;//0   
    cout << "myveca.size()=" << myveca.size() << endl;//0

    myveca.reserve(10);//预留10个空间

    cout << "myveca.capacity()=" << myveca.capacity() << endl;//10
    cout << "myveca.size()=" << myveca.size() << endl;//0

    for (int i=0;i<5;++i)
    {
        cout << "---------begin--------" << endl;
        myveca.push_back(A(i));//往容器末尾增加元素
        cout << "----------end----------" << endl;
    }


}


