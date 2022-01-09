#include<iostream>
#include<vector>

using namespace std;

struct student
{
    int num;
};

int main1()
{
    vector<int> vjihe;
    vector<student>studlist;//可以
    vector<vector<string>> strchuan;//集合里的每个元素都是一个vector对象
    vector<int*>vjihe2;//没问题
    //vector<int&>vjihe3;//语法错误 不能装引用
    return 0;
}