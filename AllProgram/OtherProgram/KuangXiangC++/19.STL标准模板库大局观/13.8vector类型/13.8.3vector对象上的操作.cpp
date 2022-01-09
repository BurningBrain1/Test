#include<iostream>
#include<vector>

using namespace std;

int main()
{
    //1 判断是否为空
    vector<int> ivec;
    if (ivec.empty())
    {
        cout << "ivec为空"<< endl;
    }

    //2 push_back向vector末尾添加元素
    vector<int> ivec2;
    ivec2.push_back(1);
    ivec2.push_back(2);
    for (int i = 3; i < 100; i++)
    {
        ivec2.push_back(i);
    }

    //3 size返回元素的个数
    cout << ivec2.size()<< endl;

    //4 clear:移除所有元素 清空容器
    ivec2.clear();
    cout << ivec2.size() << endl;//0

    //5 v[n]返回v中的第n个字符
    ivec2.clear();
    ivec2.push_back(1);
    ivec2.push_back(2);
    cout << ivec2[1] << endl;//2

    //6 赋值运算符=
    vector<int> ivec3;
    for (int i = 0; i < 100; i++)
    {
        ivec3.push_back(i);
    }
    vector<int>ivec4;
    ivec4.push_back(111);
    ivec4 = ivec3;//也得到了100个元素 原本内容被新列表取代
    //7if(ivec3==ivec4)或if(ivec3!=ivec4)不再演示

    //8 范围for的应用
    vector<int>vecvalue{1,2,3,4,5};
    for (auto& vecitem:vecvalue)//这里是引用 可以修改元素值
    {
        vecitem = 2 * vecitem;
    }
    for (auto& vecitem:vecvalue)
    {
        cout << vecitem << endl;
    }
    return 0;
}