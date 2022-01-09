#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int>iv = { 100,200,300 };//定义一个容器
    vector<int>::iterator iter;//定义迭代器 也必须是vector<int>开头

    //(1)begin返回一个迭代器类型 可以理解成返回一个迭代器
    iter = iv.begin();//如果容器中有元素 begin返回的迭代器指向的是容器中的第一个元素
                      //这里相当于iter代表着元素iv[0]

    //(2)end返回一个迭代器类型(就理解成返回一个迭代器)
    iter=iv.end();//end返回的迭代器指向的是最后一个元素的后面 是一个不存在的元素

    //(3)如果容器为空 begin返回的迭代器与end返回的迭代器相同
    vector<int>iv2;
    vector<int>::iterator iterbegin = iv2.begin();
    vector<int>::iterator iterend = iv2.end();
    if (iterbegin==iterend)
    {
        cout << "容器为空" << endl;
    }

    //(4)传统的通过迭代器访问容器中元素的方法
    vector<int>::iterator iter1;
    for (iter1 = iv.begin(); iter1 != iv.end(); iter++)
    {
        cout << *iter << endl;//100 200 300
    }

    //2.反向迭代器
    //(1)rbegin返回一个反向迭代器类型 指向容器的最后一个元素
    //(2)rend返回一个反向迭代器类型 只想容器的第一个元素前一个位置
    vector<int>iv4 = { 100,200,300 };
    for (vector<int>::reverse_iterator riter=iv4.rbegin();riter!=iv.rend();riter++)
    {
        cout << *riter << endl;//300 200 100
    }

    return 0;
}