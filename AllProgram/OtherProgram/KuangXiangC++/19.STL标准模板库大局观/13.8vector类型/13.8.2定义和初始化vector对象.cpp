#include<iostream>
#include<vector>

using namespace std;

int main2()
{
    //1 空vector并增加成员
    vector<string>mystr;//创建一个string类型的空vector对象
    mystr.push_back("abcd");
    mystr.push_back("def");

    //2 对象元素类型相同 进行对象元素复制
    vector<string>mystr2(mystr);
    vector <string>mystr3= mystr;

    //3 用初始化列表方法给初值
    vector<string>def = { "aa","bb","cc"};

    //4 创建指定数量的元素
    vector<int>ijihe(15,-200);//创建15个int类型元素的集合 每个元素都是-200
    vector<string>sjihe(5, "hello");//创建5个hello
    vector<int>ijihe2(20);//20个元素 每个都为0
    vector<string>sjihe2(5);//5个元素 每个都为""

    //5  多种初始化
    vector<int>i1(10);//圆括号括住的单个数字10表示元素数量 每个元素值默认为0
    vector<int>i2{ 10 };//{}表示单个元素 值为10
    vector<string>snor{ "hello" };//一个元素内容为hello
    vector<string>s22{ 10 };//10个元素 因为10不能作为string对象的内容 所以系统处理为了数量
    vector<string>s23{10,"hello"};//10个元素 每个元素内容都是hello
    vector<int>i3(10,1);//先数量后内容 10个元素 每个元素值为1
    vector<int>i4{ 10,1 };//2个元素 10和1 等同于初始化列表
    vector<string>{"hello"};//系统直接报编译错误

    return 0;
}