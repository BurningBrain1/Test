#include<vector>
#include<iostream>
using namespace std;

int main()
{
    //(1)(2)(3)*iter返回迭代器iter所指向的元素的引用 指向end的迭代器 不能再++
    vector<int>iv = {100,200,300};//定义一个容器
    vector<int>::iterator iter;
    for (iter=iv.begin();iter!=iv.end();++iter)
    {
        cout << *iter << endl;
    }

    //(4)iter1==iter2或iter1！=iter2 判断两个迭代器是否相等
    //(5)结构成员的引用
    struct student
    {
        int num;
    };

    vector<student> sv;
    student mystu;
    mystu.num = 100;
    sv.push_back(mystu);//把对象mystu复制到了sv容器中
               //(是复制 此时mystu和容器中的student没有直接关系)
    mystu.num = 200;//这里不会对容器中的元素产生影响 因为是复制关系
    vector<student>::iterator iter1;
    iter1= sv.begin();//指向第一个元素
    cout <<(*iter1).num << endl;
    cout <<iter1->num << endl;//两种取值方式 100
    return 0;
}