#include<vector>
#include<iostream>
using namespace std;

int main()
{
   
    vector<int>iv = { 100,200,300 };//定义一个容器
    vector<int>::const_iterator iter;
    for (iter = iv.begin(); iter != iv.end(); ++iter)
    {
        //*iter = 4;//不可以
        cout << *iter << endl;//可以 常量迭代器也可以正常从容器中读元素值
    }

    //容器带const时 必须用常量迭代器
    const vector<int>iv1 = { 100,200,300 };//定义一个容器 带const
    vector<int>::const_iterator iter1;
    for (iter = iv.begin(); iter != iv.end(); ++iter)//常量容器的迭代器会返回const迭代器
    {
        cout << *iter << endl;//可以 常量迭代器也可以正常从容器中读元素值
    }

    //cbegin与cend不管容器是不是常量容器 返回的都是常量迭代器
    vector<int> iv4={100,200,300};
    for (auto iter2=iv4.cbegin();iter2!=iv4.cend();++iter)
    {
        //*iter = 58; 错误 不能给常量赋值 说明cbegin返回的是常量迭代器
    }
    return 0;
}