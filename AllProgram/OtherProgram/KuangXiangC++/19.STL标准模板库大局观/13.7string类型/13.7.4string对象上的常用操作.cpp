#include<iostream>
#include<string>

using namespace std;

int main()
{
    //(1)判断是否为空empty()
    string s1; 
    if (s1.empty())
    {
        cout << "s1为空" << endl;
    }
    
    //(2)size()或者length() 返回字节/字符数量
    string s11;
    cout << s11.size() << endl;//0
    cout << s11.length() << endl;//0
    string s2 = "我爱中国";
    cout << s2.size() << endl;//8  1个汉字占2个字节
    cout << s2.length() << endl;//8 
    string s3 = "I Love China";
    cout << s3.size() << endl;//13
    cout << s3.length() << endl;//13

    //(3)返回s中的第n个字符
    s3[4] = 10;

    //(4)s1+s2 字符串连接 返回连接后的结果 
    string s4 = "abcd";
    string s5 = "dfsdf";
    string s6 = s4 + s5;

    //(5)s1=s2 字符串对象赋值 s2内容取代原来s1里面的内容
    s4 = s5;

    //(6)s1==s2 判断两个字符串是否相等 大小写敏感
    if (s4==s5)
    {
        cout << true << endl;
    }

    //(7)s1!=s2 判断两个字符串不相等
    if (s4!=s5)
    {
        cout << true <<endl;
    }

    //(8)s.c_str()返回一个字符串s中的内容指针（这个内容实际上就是
    //string字符串里的内容） 返回的是一个指向正规C字符串的常量指针
    string s9 = "abc";
    string s10 = "abC";
    const char* p = s10.c_str();//现在p指向s10里边的字符串了
    char str[100];
    strcpy_s(str,sizeof(str),p);//字符串内容复制到str中
    cout << str << endl;//abC

    //(9)读写string对象
    cin >> s1;//输入abc回车
    cout << s1 << endl;//输出abc

    //(10)字面值和string相加 两个字符串不能挨着相加
    string s33 = s1 + "and" + s2;

    //(11）范围for针对string的使用
    string ss = "I Love China";
    for (auto& c:ss)
    {
        c = toupper(c);//因为c是一个引用 所以相当于改变s中的值
    }
    cout << ss << endl;//I LOVE CHINA
}