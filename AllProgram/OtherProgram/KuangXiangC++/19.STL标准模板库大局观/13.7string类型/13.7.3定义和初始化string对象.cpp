#include<iostream>
#include<string>

using namespace std;

int main1()
{
    string s1; //默认初始化 代表空字符串
    string s2 = "I Love China";//把字符串复制到s2代表的一段内存中
    string s3("I Love China");
    string s4 = s2; //把s2的内容复制到了s4所代表的内存中

    int num = 6;
    string s5(num, 'a');//把s5初始化为连续num个字符'a'组成的字符串
    return 0;
}